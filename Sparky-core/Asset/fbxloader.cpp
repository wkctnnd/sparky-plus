#include "fbxloader.h"
#include <fbxsdk/scene/geometry/fbxlayer.h>
#include <fbxsdk/scene/geometry/fbxskeleton.h>
using namespace sparky::maths;
namespace sparky {

	namespace asset {


		FBXLoader::FBXLoader()
		{
			int a = 1;
		}
		// Bake node attributes and materials under this node recursively.
  // Currently only mesh, light and material.
		void FBXLoader::LoadCacheRecursive(FbxNode * pNode, FbxAnimLayer * pAnimLayer, bool pSupportVBO)
		{
			// Bake material and hook as user data.

			FbxNodeAttribute* lNodeAttribute = pNode->GetNodeAttribute();
			if (lNodeAttribute)
			{
				// Bake mesh as VBO(vertex buffer object) into GPU.
				if (lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh)
				{
					FbxMesh * lMesh = pNode->GetMesh();
					if (pSupportVBO && lMesh && !lMesh->GetUserDataPtr())
					{
						//加载mesh
						/*FbxAutoPtr<VBOMesh> lMeshCache(new VBOMesh);
						if (lMeshCache->Initialize(lMesh))
						{
							lMesh->SetUserDataPtr(lMeshCache.Release());
						}*/
					}
				}
			}

			const int lChildCount = pNode->GetChildCount();
			for (int lChildIndex = 0; lChildIndex < lChildCount; ++lChildIndex)
			{
				LoadCacheRecursive(pNode->GetChild(lChildIndex), pAnimLayer, pSupportVBO);
			}
		}

		void FBXLoader::LoadCacheRecursive(FbxScene * pScene, FbxAnimLayer * pAnimLayer, const char * pFbxFileName, bool pSupportVBO)
		{
			// Load the textures into GPU, only for file texture now
			const int lTextureCount = pScene->GetTextureCount();
			for (int lTextureIndex = 0; lTextureIndex < lTextureCount; ++lTextureIndex)
			{
				FbxTexture * lTexture = pScene->GetTexture(lTextureIndex);
				FbxFileTexture * lFileTexture = FbxCast<FbxFileTexture>(lTexture);
				if (lFileTexture && !lFileTexture->GetUserDataPtr())
				{
					// Try to load the texture from absolute path
					const FbxString lFileName = lFileTexture->GetFileName();

					// Only TGA textures are supported now.
					if (lFileName.Right(3).Upper() != "TGA")
					{
						FBXSDK_printf("Only TGA textures are supported now: %s\n", lFileName.Buffer());
						continue;
					}

					/*			GLuint lTextureObject = 0;
								bool lStatus = LoadTextureFromFile(lFileName, lTextureObject);*/

					const FbxString lAbsFbxFileName = FbxPathUtils::Resolve(pFbxFileName);
					const FbxString lAbsFolderName = FbxPathUtils::GetFolderName(lAbsFbxFileName);
					//if (!lStatus)
					//{
					//	// Load texture from relative file name (relative to FBX file)
					//	const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lFileTexture->GetRelativeFileName());
					//	lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					//}

					//if (!lStatus)
					//{
					//	// Load texture from file name only (relative to FBX file)
					//	const FbxString lTextureFileName = FbxPathUtils::GetFileName(lFileName);
					//	const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lTextureFileName);
					//	lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					//}

					//if (!lStatus)
					//{
					//	FBXSDK_printf("Failed to load texture file: %s\n", lFileName.Buffer());
					//	continue;
					//}

					//if (lStatus)
					//{
					//	GLuint * lTextureName = new GLuint(lTextureObject);
					//	lFileTexture->SetUserDataPtr(lTextureName);
					//}
				}
			}

			LoadCacheRecursive(pScene->GetRootNode(), pAnimLayer, pSupportVBO);
		}

		void FBXLoader::Initialize()
		{
			InitializeSdkObjects(mSdkManager, mScene);

			if (mSdkManager)
			{
				// Create the importer.
				int lFileFormat = -1;
				mImporter = FbxImporter::Create(mSdkManager, "");

			}
		}

		void FBXLoader::InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene)
		{
			//The first thing to do is to create the FBX Manager which is the object allocator for almost all the classes in the SDK
			pManager = FbxManager::Create();
			if (!pManager)
			{
				FBXSDK_printf("Error: Unable to create FBX Manager!\n");
				exit(1);
			}
			else FBXSDK_printf("Autodesk FBX SDK version %s\n", pManager->GetVersion());

			//Create an IOSettings object. This object holds all import/export settings.
			FbxIOSettings* ios = FbxIOSettings::Create(pManager, IOSROOT);
			pManager->SetIOSettings(ios);

			//Load plugins from the executable directory (optional)
			FbxString lPath = FbxGetApplicationDirectory();
			pManager->LoadPluginsDirectory(lPath.Buffer());

			//Create an FBX scene. This object holds most objects imported/exported from/to files.
			pScene = FbxScene::Create(pManager, "My Scene");
			if (!pScene)
			{
				FBXSDK_printf("Error: Unable to create FBX scene!\n");
				exit(1);
			}
		}

		bool FBXLoader::LoadFile(const char* filename)
		{

			int lFileFormat;
			if (!mSdkManager->GetIOPluginRegistry()->DetectReaderFileFormat(filename, lFileFormat))
			{
				// Unrecognizable file format. Try to fall back to FbxImporter::eFBX_BINARY
				lFileFormat = mSdkManager->GetIOPluginRegistry()->FindReaderIDByDescription("FBX binary (*.fbx)");;
			}
			bool lResult = false;

			// Initialize the importer by providing a filename.
			if (mImporter->Initialize(filename, lFileFormat) == true)
			{

				std::string error = mImporter->GetStatus().GetErrorString();
				if (error.size() > 0)
				{
					std::cout << error;
				}
				// File format version numbers to be populated.
				int lFileMajor, lFileMinor, lFileRevision;

				// Populate the FBX file format version numbers with the import file.
				mImporter->GetFileVersion(lFileMajor, lFileMinor, lFileRevision);

				//FbxScene * mScene;



				//单线程，仅支持一次加载一个场景
				mScene->Clear();
				lResult = mImporter->Import(mScene);

				FbxAxisSystem SceneAxisSystem = mScene->GetGlobalSettings().GetAxisSystem();
				FbxAxisSystem OurAxisSystem(FbxAxisSystem::eYAxis, FbxAxisSystem::eParityOdd, FbxAxisSystem::eRightHanded);
				if (SceneAxisSystem != OurAxisSystem)
				{
					OurAxisSystem.ConvertScene(mScene);
				}

				// Convert Unit System to what is used in this example, if needed
				FbxSystemUnit SceneSystemUnit = mScene->GetGlobalSettings().GetSystemUnit();
				if (SceneSystemUnit.GetScaleFactor() != 1.0)
				{
					//The unit in this example is centimeter.
					FbxSystemUnit::cm.ConvertScene(mScene);
				}

				
			
				mImporter->Destroy();


			}
			return lResult;

		}

		void FBXLoader::LoadResources()
		{
			FbxArray<FbxString*> AnimStackNameArray;
			mScene->FillAnimStackNameArray(AnimStackNameArray);
			for (size_t i = 0; i < AnimStackNameArray.Size(); i++)
			{
				FbxAnimStack *  AnimationStack = mScene->FindMember<FbxAnimStack>(AnimStackNameArray[i]->Buffer());
				m_AnimStacks.push_back(AnimationStack);
			}

			for (unsigned int i = 0; i < m_AnimStacks.size(); i++)
			{
				FbxAnimLayer * AnimLayer = m_AnimStacks[i]->GetMember<FbxAnimLayer>();
				if()
			}
			ProcessNode(mScene->GetRootNode());
		}

		bool FBXLoader::LoadMesh(RawMesh& rmesh)
		{
			// Get the list of all the animation stack.
			//mScene->FillAnimStackNameArray(mAnimStackNameArray);


			// Convert mesh, NURBS and patch into triangle mesh
			FbxGeometryConverter lGeomConverter(mSdkManager);
			try {
				lGeomConverter.Triangulate(mScene, /*replace*/true);
			}
			catch (std::runtime_error) {
				FBXSDK_printf("Scene integrity verification failed.\n");
				return false;
			}

			//FillPoseArray(mScene, mPoseArray);




			return true;

		}

		// Deform the vertex array in classic linear way.
		void FBXLoader::ComputeLinearDeformation(FbxAMatrix& pGlobalPosition,
			FbxMesh* pMesh,
			FbxTime& pTime,
			FbxVector4* pVertexArray,
			FbxPose* pPose)
		{
			// All the links must have the same link mode.
			//FbxCluster::ELinkMode lClusterMode = ((FbxSkin*)pMesh->GetDeformer(0, FbxDeformer::eSkin))->GetCluster(0)->GetLinkMode();

			//int lVertexCount = pMesh->GetControlPointsCount();
			//FbxAMatrix* lClusterDeformation = new FbxAMatrix[lVertexCount];
			//memset(lClusterDeformation, 0, lVertexCount * sizeof(FbxAMatrix));

			//double* lClusterWeight = new double[lVertexCount];
			//memset(lClusterWeight, 0, lVertexCount * sizeof(double));

			//if (lClusterMode == FbxCluster::eAdditive)
			//{
			//	for (int i = 0; i < lVertexCount; ++i)
			//	{
			//		lClusterDeformation[i].SetIdentity();
			//	}
			//}

			//// For all skins and all clusters, accumulate their deformation and weight
			//// on each vertices and store them in lClusterDeformation and lClusterWeight.
			//int lSkinCount = pMesh->GetDeformerCount(FbxDeformer::eSkin);
			//for (int lSkinIndex = 0; lSkinIndex < lSkinCount; ++lSkinIndex)
			//{
			//	FbxSkin * lSkinDeformer = (FbxSkin *)pMesh->GetDeformer(lSkinIndex, FbxDeformer::eSkin);

			//	int lClusterCount = lSkinDeformer->GetClusterCount();
			//	for (int lClusterIndex = 0; lClusterIndex < lClusterCount; ++lClusterIndex)
			//	{
			//		FbxCluster* lCluster = lSkinDeformer->GetCluster(lClusterIndex);
			//		if (!lCluster->GetLink())
			//			continue;

			//		FbxAMatrix lVertexTransformMatrix;
			//		ComputeClusterDeformation(pGlobalPosition, pMesh, lCluster, lVertexTransformMatrix, pTime, pPose);

			//		int lVertexIndexCount = lCluster->GetControlPointIndicesCount();
			//		for (int k = 0; k < lVertexIndexCount; ++k)
			//		{
			//			int lIndex = lCluster->GetControlPointIndices()[k];

			//			// Sometimes, the mesh can have less points than at the time of the skinning
			//			// because a smooth operator was active when skinning but has been deactivated during export.
			//			if (lIndex >= lVertexCount)
			//				continue;

			//			double lWeight = lCluster->GetControlPointWeights()[k];

			//			if (lWeight == 0.0)
			//			{
			//				continue;
			//			}

			//			// Compute the influence of the link on the vertex.
			//			FbxAMatrix lInfluence = lVertexTransformMatrix;
			//			MatrixScale(lInfluence, lWeight);

			//			if (lClusterMode == FbxCluster::eAdditive)
			//			{
			//				// Multiply with the product of the deformations on the vertex.
			//				MatrixAddToDiagonal(lInfluence, 1.0 - lWeight);
			//				lClusterDeformation[lIndex] = lInfluence * lClusterDeformation[lIndex];

			//				// Set the link to 1.0 just to know this vertex is influenced by a link.
			//				lClusterWeight[lIndex] = 1.0;
			//			}
			//			else // lLinkMode == FbxCluster::eNormalize || lLinkMode == FbxCluster::eTotalOne
			//			{
			//				// Add to the sum of the deformations on the vertex.
			//				MatrixAdd(lClusterDeformation[lIndex], lInfluence);

			//				// Add to the sum of weights to either normalize or complete the vertex.
			//				lClusterWeight[lIndex] += lWeight;
			//			}
			//		}//For each vertex			
			//	}//lClusterCount
			//}

			////Actually deform each vertices here by information stored in lClusterDeformation and lClusterWeight
			//for (int i = 0; i < lVertexCount; i++)
			//{
			//	FbxVector4 lSrcVertex = pVertexArray[i];
			//	FbxVector4& lDstVertex = pVertexArray[i];
			//	double lWeight = lClusterWeight[i];

			//	// Deform the vertex if there was at least a link with an influence on the vertex,
			//	if (lWeight != 0.0)
			//	{
			//		lDstVertex = lClusterDeformation[i].MultT(lSrcVertex);
			//		if (lClusterMode == FbxCluster::eNormalize)
			//		{
			//			// In the normalized link mode, a vertex is always totally influenced by the links. 
			//			lDstVertex /= lWeight;
			//		}
			//		else if (lClusterMode == FbxCluster::eTotalOne)
			//		{
			//			// In the total 1 link mode, a vertex can be partially influenced by the links. 
			//			lSrcVertex *= (1.0 - lWeight);
			//			lDstVertex += lSrcVertex;
			//		}
			//	}
			//}

			//delete[] lClusterDeformation;
			//delete[] lClusterWeight;
		}

		// Deform the vertex array in Dual Quaternion Skinning way.
		void FBXLoader::ComputeDualQuaternionDeformation(FbxAMatrix& pGlobalPosition,
			FbxMesh* pMesh,
			FbxTime& pTime,
			FbxVector4* pVertexArray,
			FbxPose* pPose)
		{
			//// All the links must have the same link mode.
			//FbxCluster::ELinkMode lClusterMode = ((FbxSkin*)pMesh->GetDeformer(0, FbxDeformer::eSkin))->GetCluster(0)->GetLinkMode();

			//int lVertexCount = pMesh->GetControlPointsCount();
			//int lSkinCount = pMesh->GetDeformerCount(FbxDeformer::eSkin);

			//FbxDualQuaternion* lDQClusterDeformation = new FbxDualQuaternion[lVertexCount];
			//memset(lDQClusterDeformation, 0, lVertexCount * sizeof(FbxDualQuaternion));

			//double* lClusterWeight = new double[lVertexCount];
			//memset(lClusterWeight, 0, lVertexCount * sizeof(double));

			//// For all skins and all clusters, accumulate their deformation and weight
			//// on each vertices and store them in lClusterDeformation and lClusterWeight.
			//for (int lSkinIndex = 0; lSkinIndex < lSkinCount; ++lSkinIndex)
			//{
			//	FbxSkin * lSkinDeformer = (FbxSkin *)pMesh->GetDeformer(lSkinIndex, FbxDeformer::eSkin);
			//	int lClusterCount = lSkinDeformer->GetClusterCount();
			//	for (int lClusterIndex = 0; lClusterIndex < lClusterCount; ++lClusterIndex)
			//	{
			//		FbxCluster* lCluster = lSkinDeformer->GetCluster(lClusterIndex);
			//		if (!lCluster->GetLink())
			//			continue;

			//		FbxAMatrix lVertexTransformMatrix;
			//		ComputeClusterDeformation(pGlobalPosition, pMesh, lCluster, lVertexTransformMatrix, pTime, pPose);

			//		FbxQuaternion lQ = lVertexTransformMatrix.GetQ();
			//		FbxVector4 lT = lVertexTransformMatrix.GetT();
			//		FbxDualQuaternion lDualQuaternion(lQ, lT);

			//		int lVertexIndexCount = lCluster->GetControlPointIndicesCount();
			//		for (int k = 0; k < lVertexIndexCount; ++k)
			//		{
			//			int lIndex = lCluster->GetControlPointIndices()[k];

			//			// Sometimes, the mesh can have less points than at the time of the skinning
			//			// because a smooth operator was active when skinning but has been deactivated during export.
			//			if (lIndex >= lVertexCount)
			//				continue;

			//			double lWeight = lCluster->GetControlPointWeights()[k];

			//			if (lWeight == 0.0)
			//				continue;

			//			// Compute the influence of the link on the vertex.
			//			FbxDualQuaternion lInfluence = lDualQuaternion * lWeight;
			//			if (lClusterMode == FbxCluster::eAdditive)
			//			{
			//				// Simply influenced by the dual quaternion.
			//				lDQClusterDeformation[lIndex] = lInfluence;

			//				// Set the link to 1.0 just to know this vertex is influenced by a link.
			//				lClusterWeight[lIndex] = 1.0;
			//			}
			//			else // lLinkMode == FbxCluster::eNormalize || lLinkMode == FbxCluster::eTotalOne
			//			{
			//				if (lClusterIndex == 0)
			//				{
			//					lDQClusterDeformation[lIndex] = lInfluence;
			//				}
			//				else
			//				{
			//					// Add to the sum of the deformations on the vertex.
			//					// Make sure the deformation is accumulated in the same rotation direction. 
			//					// Use dot product to judge the sign.
			//					double lSign = lDQClusterDeformation[lIndex].GetFirstQuaternion().DotProduct(lDualQuaternion.GetFirstQuaternion());
			//					if (lSign >= 0.0)
			//					{
			//						lDQClusterDeformation[lIndex] += lInfluence;
			//					}
			//					else
			//					{
			//						lDQClusterDeformation[lIndex] -= lInfluence;
			//					}
			//				}
			//				// Add to the sum of weights to either normalize or complete the vertex.
			//				lClusterWeight[lIndex] += lWeight;
			//			}
			//		}//For each vertex
			//	}//lClusterCount
			//}

			////Actually deform each vertices here by information stored in lClusterDeformation and lClusterWeight
			//for (int i = 0; i < lVertexCount; i++)
			//{
			//	FbxVector4 lSrcVertex = pVertexArray[i];
			//	FbxVector4& lDstVertex = pVertexArray[i];
			//	double lWeightSum = lClusterWeight[i];

			//	// Deform the vertex if there was at least a link with an influence on the vertex,
			//	if (lWeightSum != 0.0)
			//	{
			//		lDQClusterDeformation[i].Normalize();
			//		lDstVertex = lDQClusterDeformation[i].Deform(lDstVertex);

			//		if (lClusterMode == FbxCluster::eNormalize)
			//		{
			//			// In the normalized link mode, a vertex is always totally influenced by the links. 
			//			lDstVertex /= lWeightSum;
			//		}
			//		else if (lClusterMode == FbxCluster::eTotalOne)
			//		{
			//			// In the total 1 link mode, a vertex can be partially influenced by the links. 
			//			lSrcVertex *= (1.0 - lWeightSum);
			//			lDstVertex += lSrcVertex;
			//		}
			//	}
			//}

			//delete[] lDQClusterDeformation;
			//delete[] lClusterWeight;
		}


		// Deform the vertex array according to the links contained in the mesh and the skinning type.
		void FBXLoader::ComputeSkinDeformation(FbxAMatrix& pGlobalPosition,
			FbxMesh* pMesh,
			FbxTime& pTime,
			FbxVector4* pVertexArray,
			FbxPose* pPose)
		{
			FbxSkin * lSkinDeformer = (FbxSkin *)pMesh->GetDeformer(0, FbxDeformer::eSkin);
			FbxSkin::EType lSkinningType = lSkinDeformer->GetSkinningType();

			if (lSkinningType == FbxSkin::eLinear || lSkinningType == FbxSkin::eRigid)
			{
				ComputeLinearDeformation(pGlobalPosition, pMesh, pTime, pVertexArray, pPose);
			}
			else if (lSkinningType == FbxSkin::eDualQuaternion)
			{
				ComputeDualQuaternionDeformation(pGlobalPosition, pMesh, pTime, pVertexArray, pPose);
			}
			else if (lSkinningType == FbxSkin::eBlend)
			{
				int lVertexCount = pMesh->GetControlPointsCount();

				FbxVector4* lVertexArrayLinear = new FbxVector4[lVertexCount];
				memcpy(lVertexArrayLinear, pMesh->GetControlPoints(), lVertexCount * sizeof(FbxVector4));

				FbxVector4* lVertexArrayDQ = new FbxVector4[lVertexCount];
				memcpy(lVertexArrayDQ, pMesh->GetControlPoints(), lVertexCount * sizeof(FbxVector4));

				ComputeLinearDeformation(pGlobalPosition, pMesh, pTime, lVertexArrayLinear, pPose);
				ComputeDualQuaternionDeformation(pGlobalPosition, pMesh, pTime, lVertexArrayDQ, pPose);

				// To blend the skinning according to the blend weights
				// Final vertex = DQSVertex * blend weight + LinearVertex * (1- blend weight)
				// DQSVertex: vertex that is deformed by dual quaternion skinning method;
				// LinearVertex: vertex that is deformed by classic linear skinning method;
				int lBlendWeightsCount = lSkinDeformer->GetControlPointIndicesCount();
				for (int lBWIndex = 0; lBWIndex < lBlendWeightsCount; ++lBWIndex)
				{
					double lBlendWeight = lSkinDeformer->GetControlPointBlendWeights()[lBWIndex];
					pVertexArray[lBWIndex] = lVertexArrayDQ[lBWIndex] * lBlendWeight + lVertexArrayLinear[lBWIndex] * (1 - lBlendWeight);
				}
			}
		}

		//加载骨骼的动画信息
		void FBXLoader::LoadNodeCurve(FbxAnimLayer* pAnimationLayer, FbxNode* pNode, StackTimeSpan& timeSpan)
		{
			KTime       keyTimer;

			unsigned long millseconds;

			for (UINT i = 0; i < timeSpan.mKeyNums; ++i)
			{
				millseconds = timeSpan.mStart + (float)i * timeSpan.mStep;
				keyTimer.SetMilliSeconds(millseconds);

				// 计算得到当前结点在当前时刻下所对应的空间局部和全局矩阵                
				// 局部矩阵对于Skeleton是必需的，因需要使用它来计算父子Skeleton之间的空间关系 
				KFbxXMatrix curveKeyLocalMatrix = pNode->EvaluateLocalTransform(keyTimer);
				KFbxXMatrix curveKeyGlobalMatrix = pNode->EvaluateGlobalTransform(keyTimer);
			}
		}

		void FBXLoader::ProcessSkeleton(FbxNode* pNode, Skeleton* skeleton, int parentindex, FbxAnimLayer* animationlayer)
		{

			FbxSkeleton* lSkeleton = (FbxSkeleton*)pNode->GetNodeAttribute();


			// Only draw the skeleton if it's a limb node and if 
			// the parent also has an attribute of type skeleton.
			if (lSkeleton->GetSkeletonType() == FbxSkeleton::eLimbNode)
			{
				/*GlDrawLimbNode(pParentGlobalPosition, pGlobalPosition);*/
				joint* j = 0;
				if (parentindex == -1)
				{
					j = new joint(0, pNode->GetName());
					if (!animationlayer)
					{

					}
				}
				else
				{
					j = new joint(skeleton->joints[parentindex], pNode->GetName());
					skeleton->joints[parentindex]->children.push_back(j);
				}
					
				
				skeleton->joints.push_back(j);
			}


			////we need to get the number of clusters
			//const int lSkinCount = lMesh->GetDeformerCount(FbxDeformer::eSkin);
			//int lClusterCount = 0;
			//for (int lSkinIndex = 0; lSkinIndex < lSkinCount; ++lSkinIndex)
			//{
			//	lClusterCount += ((FbxSkin *)(lMesh->GetDeformer(lSkinIndex, FbxDeformer::eSkin)))->GetClusterCount();
			//}
			//if (lClusterCount)
			//{
			//	// Deform the vertex array with the skin deformer.
			//	ComputeSkinDeformation(pGlobalPosition, lMesh, pTime, lVertexArray, pPose);
			//}

			for (int i = 0; i < pNode->GetChildCount(); ++i)
			{
				if(pNode->GetNodeAttribute()&& pNode->GetNodeAttribute()->GetAttributeType() == FbxNodeAttribute::eSkeleton)
					ProcessSkeleton(pNode->GetChild(i), skeleton, skeleton->joints.size()-1);
			}

		}

		void FBXLoader::ProcessMesh(FbxNode* pNode)
		{
			FbxMesh* pMesh = pNode->GetMesh();
			if (pMesh == NULL)
			{
				return;
			}

			const bool lHasSkin = pMesh->GetDeformerCount(FbxDeformer::eSkin) > 0;

			//static mesh
			if (!lHasSkin)
			{
				RawMesh *rawstaticmesh = new RawMesh();

				ReadRawStaticMesh(pMesh, rawstaticmesh);

				m_MeshAsset.push_back(rawstaticmesh);

			}
			else  //skin mesh
			{
				RawSkinMesh *rawskinmesh = new RawSkinMesh();
				ReadRawSkinMesh(pMesh, rawskinmesh);
				m_SkinMeshAsset.push_back(rawskinmesh);
			}

		}

		void FBXLoader::ReadRawStaticMesh(FbxMesh* pMesh, RawMesh* rawstaticmesh)
		{
			if (pMesh->GetElementVertexColorCount() < 1)
			{
				return;
			}

			int triangleCount = pMesh->GetPolygonCount();
			int vertexCounter = 0;

			for (int i = 0; i < triangleCount; ++i)
			{
				for (int j = 0; j < 3; j++)
				{
					int ctrlPointIndex = pMesh->GetPolygonVertex(i, j);

					// Read the vertex




					ReadPosition(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Position[j]);

					// Read the color of each vertex
					ReadColor(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Color[j]);

					// Read the UV of each vertex
					for (int k = 0; k < 2; ++k)
						/*			{
										ReadUV(pMesh, ctrlPointIndex, pMesh->GetTextureUVIndex(i, j), k, &(uv[j][k]));
									}*/

									// Read the normal of each vertex
						//ReadNormal(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Normal[j]);

					// Read the tangent of each vertex
					//ReadTangent(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Tangent[j]);

					vertexCounter++;
				}

				// 根据读入的信息组装三角形，并以某种方式使用即可，比如存入到列表中、保存到文件等...
			}




		}

		void FBXLoader::ReadColor(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec4& color)
		{
			FbxGeometryElementVertexColor* pVertexColor = pMesh->GetElementVertexColor(0);
			switch (pVertexColor->GetMappingMode())
			{
			case FbxGeometryElement::eByControlPoint:
			{
				switch (pVertexColor->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					color.x = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mAlpha;
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int id = pVertexColor->GetIndexArray().GetAt(ctrlPointIndex);
					color.x = pVertexColor->GetDirectArray().GetAt(id).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(id).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(id).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(id).mAlpha;
				}
				break;

				default:
					break;
				}
			}
			break;

			case FbxGeometryElement::eByPolygonVertex:
			{
				switch (pVertexColor->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{

					color.x = pVertexColor->GetDirectArray().GetAt(vertexCount).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(vertexCount).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(vertexCount).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(vertexCount).mAlpha;
				}
				break;
				case FbxGeometryElement::eIndexToDirect:
				{
					int id = pVertexColor->GetIndexArray().GetAt(vertexCount);
					color.x = pVertexColor->GetDirectArray().GetAt(id).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(id).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(id).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(id).mAlpha;
				}
				break;
				default:
					break;
				}
			}
			break;
			}
		}
		/*void FBXLoader::ReadColor(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec4& color)
		{
			FbxGeometryElementVertexColor* pVertexColor = pMesh->GetElementVertexColor(0);
			switch (pVertexColor->GetMappingMode())
			{
			case FbxGeometryElement::eByControlPoint:
			{
				switch (pVertexColor->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					color.x = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(ctrlPointIndex).mAlpha;
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int id = pVertexColor->GetIndexArray().GetAt(ctrlPointIndex);
					color.x = pVertexColor->GetDirectArray().GetAt(id).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(id).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(id).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(id).mAlpha;
				}
				break;

				default:
					break;
				}
			}
			break;

			case FbxGeometryElement::eByPolygonVertex:
			{
				switch (pVertexColor->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					color.x = pVertexColor->GetDirectArray().GetAt(vertexCount).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(vertexCount).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(vertexCount).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(vertexCount).mAlpha;
				}
				break;
				case FbxGeometryElement::eIndexToDirect:
				{
					int id = pVertexColor->GetIndexArray().GetAt(vertexCount);
					color.x = pVertexColor->GetDirectArray().GetAt(id).mRed;
					color.y = pVertexColor->GetDirectArray().GetAt(id).mGreen;
					color.z = pVertexColor->GetDirectArray().GetAt(id).mBlue;
					color.w = pVertexColor->GetDirectArray().GetAt(id).mAlpha;
				}
				break;
				default:
					break;
				}
			}
			break;
			}
		}
*/
		void FBXLoader::ReadRawSkinMesh(FbxMesh* pMesh, RawSkinMesh* skinmesh)
		{
			if (pMesh->GetElementVertexColorCount() < 1)
			{
				return;
			}

			int triangleCount = pMesh->GetPolygonCount();
			int vertexCounter = 0;

			for (int i = 0; i < triangleCount; ++i)
			{
				for (int j = 0; j < 3; j++)
				{
					int ctrlPointIndex = pMesh->GetPolygonVertex(i, j);

					// Read the vertex

					ReadPosition(pMesh, ctrlPointIndex, vertexCounter, skinmesh->m_Position[j]);

					// Read the color of each vertex
					ReadColor(pMesh, ctrlPointIndex, vertexCounter, skinmesh->m_Color[j]);

					// Read the UV of each vertex
					for (int k = 0; k < 2; ++k)
					{
						//ReadUV(pMesh, ctrlPointIndex, pMesh->GetTextureUVIndex(i, j), k, &(uv[j][k]));
					}

									// Read the normal of each vertex
					//	ReadNormal(pMesh, ctrlPointIndex, vertexCounter, skinmesh->m_Normal[j]);

					// Read the tangent of each vertex
					//ReadTangent(pMesh, ctrlPointIndex, vertexCounter, skinmesh->m_Tangent[j]);

					vertexCounter++;
				}

				// 根据读入的信息组装三角形，并以某种方式使用即可，比如存入到列表中、保存到文件等...
			}



		}
	/*	void FBXLoader::ReadTangent(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter)
		{

		}
		void FBXLoader::ReadNormal(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter)
		{

		}*/
		void FBXLoader::ReadPosition(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec3& position)
		{
			FbxVector4* pCtrlPoint = pMesh->GetControlPoints();

			position.x = pCtrlPoint[ctrlPointIndex].mData[0];
			position.y = pCtrlPoint[ctrlPointIndex].mData[1];
			position.z = pCtrlPoint[ctrlPointIndex].mData[2];
		}


		void FBXLoader::ReadUV(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount)
		{


		}


		void FBXLoader::ProcessNode(FbxNode* pNode, FbxAnimLayer* animationlayer)
		{

			FbxNodeAttribute::EType attributeType;

			if (pNode->GetNodeAttribute())
			{
				switch (pNode->GetNodeAttribute()->GetAttributeType())
				{
				case FbxNodeAttribute::eMesh:
					ProcessMesh(pNode);
					break;
				case FbxNodeAttribute::eSkeleton:
					Skeleton* skeleton = new Skeleton();
					ProcessSkeleton(pNode, skeleton , -1, animationlayer);
					m_SkeletalAsset.push_back(skeleton);
					return;
					//case FbxNodeAttribute::e

				}
			}

			for (int i = 0; i < pNode->GetChildCount(); ++i)
			{
				ProcessNode(pNode->GetChild(i));
			}


		}
		bool FBXLoader::SetCurrentAnimStack(int pIndex)
		{
			//const int lAnimStackCount = mAnimStackNameArray.GetCount();
			//if (!lAnimStackCount || pIndex >= lAnimStackCount)
			//{
			//	return false;
			//}

			//// select the base layer from the animation stack
			//FbxAnimStack * lCurrentAnimationStack = mScene->FindMember<FbxAnimStack>(mAnimStackNameArray[pIndex]->Buffer());
			//if (lCurrentAnimationStack == NULL)
			//{
			//	// this is a problem. The anim stack should be found in the scene!
			//	return false;
			//}

			//// we assume that the first animation layer connected to the animation stack is the base layer
			//// (this is the assumption made in the FBXSDK)
			//mCurrentAnimLayer = lCurrentAnimationStack->GetMember<FbxAnimLayer>();
			//mScene->SetCurrentAnimationStack(lCurrentAnimationStack);

			//FbxTakeInfo* lCurrentTakeInfo = mScene->GetTakeInfo(*(mAnimStackNameArray[pIndex]));
			//if (lCurrentTakeInfo)
			//{
			//	mStart = lCurrentTakeInfo->mLocalTimeSpan.GetStart();
			//	mStop = lCurrentTakeInfo->mLocalTimeSpan.GetStop();
			//}
			//else
			//{
			//	// Take the time line value
			//	FbxTimeSpan lTimeLineTimeSpan;
			//	mScene->GetGlobalSettings().GetTimelineDefaultTimeSpan(lTimeLineTimeSpan);

			//	mStart = lTimeLineTimeSpan.GetStart();
			//	mStop = lTimeLineTimeSpan.GetStop();
			//}

			//// check for smallest start with cache start
			//if (mCache_Start < mStart)
			//	mStart = mCache_Start;

			//// check for biggest stop with cache stop
			//if (mCache_Stop > mStop)
			//	mStop = mCache_Stop;

			//// move to beginning
			//mCurrentTime = mStart;

			//// Set the scene status flag to refresh 
			//// the scene in the next timer callback.
			//mStatus = MUST_BE_REFRESHED;

			return true;
		}

	}
}