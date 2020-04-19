#include "fbxloader.h"
#include <fbxsdk/scene/geometry/fbxlayer.h>
#include <fbxsdk/scene/geometry/fbxskeleton.h>
#include <list>
#include "animation/keyvaluenode.h"
//https://blog.csdn.net/jxw167/article/details/81630899
//https://blog.csdn.net/guizhidaoni/article/details/104940957
using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky {

	namespace asset {

		void FBXEasyMeshPostProcess::Process(std::vector<InterMediateMesh*>& intermediatemeharray)
		{
			for (unsigned int i = 0; i < intermediatemeharray.size(); i++)
			{
				if (intermediatemeharray[i]->VertexArray[0]->CurrentIndex == -1)
				{

					RawMesh* mesh = new RawMesh();
					for (unsigned int j=0;j<intermediatemeharray[i]->VertexArray.size();i++)
					{
						mesh->m_Position.push_back(intermediatemeharray[i]->VertexArray[j]->Position);
						mesh->m_Normal.push_back(intermediatemeharray[i]->VertexArray[j]->Normal);
						mesh->m_Tangent.push_back(intermediatemeharray[i]->VertexArray[j]->Tangent);
					}
			
					m_MeshAsset.push_back(mesh);
				}
				else
				{
					RawSkinMesh* skinmesh = new RawSkinMesh();
					for (unsigned int j = 0; j < intermediatemeharray[i]->VertexArray.size(); i++)
					{
						skinmesh->m_Position.push_back(intermediatemeharray[i]->VertexArray[j]->Position);
						skinmesh->m_Normal.push_back(intermediatemeharray[i]->VertexArray[j]->Normal);
						skinmesh->m_Tangent.push_back(intermediatemeharray[i]->VertexArray[j]->Tangent);
						skinmesh->m_BoneIndex.push_back(vec4(intermediatemeharray[i]->VertexArray[j]->BoneIndex[0], intermediatemeharray[i]->VertexArray[j]->BoneIndex[1], intermediatemeharray[i]->VertexArray[j]->BoneIndex[2], intermediatemeharray[i]->VertexArray[j]->BoneIndex[3]));
					}
					m_SkinMeshAsset.push_back(skinmesh);
				}
			}
		}
		
		FBXLoader::FBXLoader()
		{
			int a = 1;
			m_PostProcess = new FBXEasyMeshPostProcess();
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

		mat4 FBXLoader::ConvertFBXMatrix(FbxAMatrix& fbxmat)
		{
			mat4 matrix;
			for (unsigned int i=0;i<4;i++)
			{
				for (unsigned int j=0;j<4;j++)
				{
					matrix.elements[i * 4 + j] = fbxmat.Get(i, j);
				}
			}
			return matrix;
		}

		vec4 FBXLoader::ConvertFBXVec4(FbxVector4& fbxvec)
		{
			vec4 vec(fbxvec[0], fbxvec[1], fbxvec[2], fbxvec[3]);
			return vec;
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
	/*		for (unsigned int i = 0; i < mScene->GetCharacterPoseCount(); i++)
			{
				FbxCharacterPose* pose = mScene->GetCharacterPose(i);
			}*/
		
			LoadAnimationData();
			ProcessNode(mScene->GetRootNode());
			LoadSkinData();
			PostProcess();
		}

		void FBXLoader::PostProcess()
		{
			m_PostProcess->Process(m_InterMeshArray);
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
		//void FBXLoader::LoadNodeCurve(FbxAnimLayer* pAnimationLayer, FbxNode* pNode)
		//{
		//	unsigned long millseconds;
		//	for (unsigned int i = 0; i < m_ClipAsset.size(); i++)
		//	{
		//		FbxTimeSpan& span = m_ClipInfos[i];
		//		unsigned int framecount = span.GetDuration().GetFrameCount();
		//		for (unsigned int j = 0; j < framecount; ++j)
		//		{

		//			
		//			FbxTime keyTimer;
		//			unsigned long t0 = span.GetDuration().GetFramedTime().GetMilliSeconds();
		//			float t1 = span.GetDuration().GetMilliSeconds() / framecount;
		//			millseconds = (span.GetStart() + t1 * (float)j).Get();
		//			keyTimer.SetMilliSeconds(millseconds);

		//			// 计算得到当前结点在当前时刻下所对应的空间局部和全局矩阵                
		//			// 局部矩阵对于Skeleton是必需的，因需要使用它来计算父子Skeleton之间的空间关系 
		//			//pAnimationLayer->

		//			FbxAMatrix curveKeyLocalMatrix = pNode->EvaluateLocalTransform(keyTimer);
		//			FbxAMatrix curveKeyGlobalMatrix = pNode->EvaluateGlobalTransform(keyTimer);
		//			
		//			FbxVector4 curveKeyLocalTranslate = pNode->EvaluateLocalTranslation(keyTimer);
		//			FbxVector4 curveKeyLocalScale = pNode->EvaluateLocalScaling(keyTimer);
		//			FbxVector4 curveKeyLocalRotate = pNode->EvaluateLocalRotation(keyTimer);

		//			vec3 translate(curveKeyLocalTranslate.mData[0], curveKeyLocalTranslate.mData[1], curveKeyLocalTranslate.mData[2]);
		//			vec3 scale(curveKeyLocalScale.mData[0], curveKeyLocalScale.mData[1], curveKeyLocalScale.mData[2]);
		//			Quaternion quat(curveKeyLocalRotate.mData[0], curveKeyLocalRotate.mData[1], curveKeyLocalRotate.mData[2], curveKeyLocalRotate.mData[3]);
		//			
		//			//需要修改成property
		//			//SkeletonPose pose(translate,scale,quat);
		//			//m_ClipAsset[i]->LocalPose.push_back(pose);
		//			//m_ClipAsset[i]->WorldPose.push_back(ConvertFBXMatrix(curveKeyLocalMatrix));
		//		}
		//	}
		//
		//}

		void FBXLoader::LoadNodeCurve(FbxAnimLayer* pAnimationLayer, AnimationLayer* layer, FbxNode* pNode)
		{
			unsigned long millseconds;
			for (unsigned int i = 0; i < m_ClipAsset.size(); i++)
			{
				FbxTimeSpan& span = m_ClipInfos[i];
				unsigned int framecount = span.GetDuration().GetFrameCount();
				for (unsigned int j = 0; j < framecount; ++j)
				{

					
					FbxTime keyTimer;
					unsigned long t0 = span.GetDuration().GetFramedTime().GetMilliSeconds();
					float t1 = span.GetDuration().GetMilliSeconds() / framecount;
					millseconds = (span.GetStart() + t1 * (float)j).Get();
					keyTimer.SetMilliSeconds(millseconds);

					// 计算得到当前结点在当前时刻下所对应的空间局部和全局矩阵                
					// 局部矩阵对于Skeleton是必需的，因需要使用它来计算父子Skeleton之间的空间关系 
					//pAnimationLayer->
					FbxAnimCurve* Curve[3];
					Curve[0] = pNode->LclTranslation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_X);
					Curve[1] = pNode->LclTranslation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Y);
					Curve[2] = pNode->LclTranslation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Z);
					//pNode->LclTranslation.GetCurveNode()
					
					KeyValueNode<vec3> *keyvaluenode = new KeyValueNode<vec3>(Translate_Type);

					for (int i = 0; i < 3; i++)
					{
						int keycount = Curve[i]->KeyGetCount();
						
						if (keycount > 0)
						{
							KeyValueCollection *valuecollection = new KeyValueCollection();
							FbxAnimCurveDef::EInterpolationType fbxtype = Curve[i]->KeyGetInterpolation(0);

							switch (fbxtype)
							{
							case FbxAnimCurveDef::eInterpolationLinear:
								valuecollection->SetInterpolatorType(Linear_Type);
							default:
								valuecollection->SetInterpolatorType(Linear_Type);
								break;
							}

							for (int i = 0; i < keycount; i++)
							{
								FbxAnimCurveKey curvekey = Curve[i]->KeyGet(i);
								float data = curvekey.GetValue();
								FbxTime time = curvekey.GetTime();

								KeyValue value(data, time.Get());
								valuecollection->AddKeyValue(value);
							}
							

						}
						
						
						
					}
					


					Curve[0] = pNode->LclRotation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_X);
					Curve[1] = pNode->LclRotation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Y);
					Curve[2] = pNode->LclRotation.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Z);

					Curve[0] = pNode->LclScaling.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_X);
					Curve[1] = pNode->LclScaling.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Y);
					Curve[2] = pNode->LclScaling.GetCurve(pAnimationLayer, FBXSDK_CURVENODE_COMPONENT_Z);

					
					FbxAMatrix curveKeyGlobalMatrix = pNode->EvaluateGlobalTransform(keyTimer);
					
					FbxVector4 curveKeyLocalTranslate = pNode->EvaluateLocalTranslation(keyTimer);
					FbxVector4 curveKeyLocalScale = pNode->EvaluateLocalScaling(keyTimer);
					FbxVector4 curveKeyLocalRotate = pNode->EvaluateLocalRotation(keyTimer);

					vec3 translate(curveKeyLocalTranslate.mData[0], curveKeyLocalTranslate.mData[1], curveKeyLocalTranslate.mData[2]);
					vec3 scale(curveKeyLocalScale.mData[0], curveKeyLocalScale.mData[1], curveKeyLocalScale.mData[2]);
					Quaternion quat(curveKeyLocalRotate.mData[0], curveKeyLocalRotate.mData[1], curveKeyLocalRotate.mData[2], curveKeyLocalRotate.mData[3]);
					
					//需要修改成property
					//SkeletonPose pose(translate,scale,quat);
					//m_ClipAsset[i]->LocalPose.push_back(pose);
					//m_ClipAsset[i]->WorldPose.push_back(ConvertFBXMatrix(curveKeyLocalMatrix));
				}
			}
		
		}

		void FBXLoader::ProcessSkeleton(FbxNode* pNode, Skeleton* skeleton, int parentindex, FbxAnimLayer* animationlayer, AnimationLayer* layer, SkeletonClip** pose)
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
					/*if (!animationlayer)
					{
						*pose = new SkeletonClip();
					}*/
				}
				else
				{
					j = new joint(skeleton->joints[parentindex], pNode->GetName());
					skeleton->joints[parentindex]->children.push_back(j);

					
					
				}
					
				LoadNodeCurve(animationlayer, layer, pNode);

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

		void FBXLoader::ProcessMesh(FbxNode* pNode, FbxAnimLayer* animationlayer)
		{
			FbxMesh* pMesh = pNode->GetMesh();
			if (pMesh == NULL)
			{
				return;
			}

			const bool lHasSkin = pMesh->GetDeformerCount(FbxDeformer::eSkin) > 0;
			InterMediateMesh *intermesh = new InterMediateMesh();
			ReadIntemediateMesh(pMesh, intermesh);
			m_InterMeshArray.push_back(intermesh);
			//static mesh
			//if (!lHasSkin)
			//{
			//	//RawMesh *rawstaticmesh = new RawMesh();

			//	InterMediateMesh *intermesh = new InterMediateMesh();
			//	ReadRawStaticMesh(pMesh, intermesh);

			//	m_MeshAsset.push_back(rawstaticmesh);

			//}
			//else  //skin mesh
			//{
			//	RawSkinMesh *rawskinmesh = new RawSkinMesh();
			//	ReadRawSkinMesh(pMesh, rawskinmesh);
			//	m_SkinMeshAsset.push_back(rawskinmesh);
			//	m_FbxMeshProcessing.push_back(pMesh);

			//	
			//}

		}

		void FBXLoader::ReadIntemediateMesh(FbxMesh* pMesh, InterMediateMesh* rawstaticmesh)
		{
			if (pMesh->GetElementVertexColorCount() < 1)
			{
				return;
			}

			int triangleCount = pMesh->GetPolygonCount();
			int vertexCounter = 0;

			FbxVector4* ctrlPoint = pMesh->GetControlPoints();
			int ctrlpointcount = pMesh->GetControlPointsCount();
			rawstaticmesh->VertexArray.resize(triangleCount * 3);
			//for (unsigned int i = 0; i < ctrlpointcount; i++)
			//{
			//	rawstaticmesh->m_Position[i].x = ctrlPoint[i].mData[0];
			//	rawstaticmesh->m_Position[i].y = ctrlPoint[i].mData[1];
			//	rawstaticmesh->m_Position[i].z = ctrlPoint[i].mData[2];
			//}
			FbxArray<FbxVector4>  pNormals;
			pMesh->GetPolygonVertexNormals(pNormals);
			for (int i = 0; i < triangleCount; ++i)
			{
				for (int j = 0; j < 3; j++)
				{
					int ctrlPointIndex = pMesh->GetPolygonVertex(i, j);

					// Read the vertex

					//pMesh->
					rawstaticmesh->Faces.push_back(ctrlPointIndex);

					ReadPosition(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->VertexArray[vertexCounter]->Position);

					// Read the color of each vertex
					ReadColor(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->VertexArray[vertexCounter]->Color);

					// Read the UV of each vertex
					for (int k = 0; k < 2; ++k)
					{

					}
						/*			{
										ReadUV(pMesh, ctrlPointIndex, pMesh->GetTextureUVIndex(i, j), k, &(uv[j][k]));
									}*/

									// Read the normal of each vertex
						//ReadNormal(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Normal[j]);

					// Read the tangent of each vertex
					//ReadTangent(pMesh, ctrlPointIndex, vertexCounter, rawstaticmesh->m_Tangent[j]);
					if (rawstaticmesh->CtrlVertices.find(ctrlPointIndex) == rawstaticmesh->CtrlVertices.end())
					{
						rawstaticmesh->CtrlVertices.insert(std::pair<unsigned int, std::list<InterVertexData*>>(ctrlPointIndex, std::list<InterVertexData*>()));
					}
					rawstaticmesh->CtrlVertices[ctrlPointIndex].push_back(rawstaticmesh->VertexArray[vertexCounter]);
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
					//SkeletonClip* pose;
					for (int i = 0; i < m_FBXAnimLayers.size(); i++)
						ProcessSkeleton(pNode, skeleton , -1, m_FBXAnimLayers[i], m_AnimationLayers[i]);
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


		//加载骨骼权重
		void FBXLoader::AssociateSkeletonWithCtrlPoint(FbxMesh* pMesh, InterMediateMesh* interskinmesh)
		{
			if (!pMesh || m_SkeletalAsset.size()!=0)
			{
				return;
			}

			int ctrlPointCount = pMesh->GetControlPointsCount();
			int deformerCount = pMesh->GetDeformerCount();

			// 初始化相应的列表
			//ctrlPointSkeletonList.SetCapacity(ctrlPointCount);
			//ctrlPointSkeletonList.setListSize(ctrlPointCount);

			FbxDeformer* pFBXDeformer;
			FbxSkin*     pFBXSkin;

			for (int i = 0; i < deformerCount; ++i)
			{
				pFBXDeformer = pMesh->GetDeformer(i);

				if (pFBXDeformer == NULL)
				{
					continue;
				}

				// 只考虑eSKIN的管理方式
				if (pFBXDeformer->GetDeformerType() != FbxDeformer::eSkin)
				{
					continue;
				}

				pFBXSkin = (FbxSkin*)(pFBXDeformer);
				if (pFBXSkin == NULL)
				{
					continue;
				}

				AssociateSkeletonWithCtrlPoint(pFBXSkin, interskinmesh);
			}
		}

		void FBXLoader::AssociateSkeletonWithCtrlPoint(FbxSkin* pSkin, InterMediateMesh* interskinmesh)
		{
			if (!pSkin || m_SkeletalAsset.size() != 0 || !interskinmesh)
			{
				return;
			}

			FbxCluster::ELinkMode linkMode = FbxCluster::eNormalize;
			FbxCluster* pCluster;
			FbxNode*    pLinkNode;
			int         jointIndex;
			joint*		pJoint;
			//FbxXMatrix  transformMatrix, transformLinkMatrix;
			int          clusterCount = pSkin->GetClusterCount();

			// 处理当前Skin中的每个Cluster（对应到Skeleton）
			for (int i = 0; i < clusterCount; ++i)
			{
				pCluster = pSkin->GetCluster(i);

				if (!pCluster)
				{
					continue;
				}
				//double* weight = pCluster->GetControlPointWeights();
				pLinkNode = pCluster->GetLink();

				if (!pLinkNode)
				{
					continue;
				}

				// 通过Skeleton管理器搜索到当前Cluster所对应的Skeleton，并与Cluster进行关联
				jointIndex = GetJointIndex(pLinkNode->GetName());

				// ... //关联Skeleton与Cluster

				if (jointIndex < 0)
				{
					continue;
				}

				pJoint = GetJoint(jointIndex);

				// 得到每个Cluster（Skeleton）所对应的Transform和TransformLink矩阵，后面具体说明
				//pCluster->GetTransformMatrix(transformMatrix);
				//pCluster->GetTransformLinkMatrix(transformLinkMatrix);

				// 其它适宜的操作，将Transform、TransformLink转换为映射矩阵并存储到相应的Skeleton中
				// ...

				int     associatedCtrlPointCount = pCluster->GetControlPointIndicesCount();
				int*    pCtrlPointIndices = pCluster->GetControlPointIndices();
				double* pCtrlPointWeights = pCluster->GetControlPointWeights();
				int     ctrlPointIndex;

				// 遍历当前Cluster所影响到的每个Vertex，并将对相应的信息做记录以便Skinning时使用
				for (int j = 0; j < associatedCtrlPointCount; ++j)
				{
					ctrlPointIndex = pCtrlPointIndices[j];
					if (interskinmesh->CtrlVertices.find(ctrlPointIndex) != interskinmesh->CtrlVertices.end())
					{
						for (auto iter = interskinmesh->CtrlVertices[ctrlPointIndex].begin(); iter != interskinmesh->CtrlVertices[ctrlPointIndex].end(); iter++)
						{
						 
								if ((*iter)->CurrentIndex < 3)
								{
									(*iter)->CurrentIndex++;
									(*iter)->BoneIndex[(*iter)->CurrentIndex] = jointIndex;
									(*iter)->BoneWeight[(*iter)->CurrentIndex] = pCtrlPointWeights[ctrlPointIndex];
								}
							
							
						}
					}
						
				}
			}
		}

		void FBXLoader::LoadSkinData()
		{
			//intermesharray.resize(m_FbxMeshProcessing.size());
			for (unsigned int i = 0; i < m_FbxMeshProcessing.size(); i++)
			{
				AssociateSkeletonWithCtrlPoint(m_FbxMeshProcessing[i], m_InterMeshArray[i]);
			}
		
		}

		void FBXLoader::LoadAnimationData()
		{
			FbxArray<FbxString*> AnimStackNameArray;
			mScene->FillAnimStackNameArray(AnimStackNameArray);

	
			int numstacks = mScene->GetSrcObjectCount<FbxAnimStack>();
	 
			for (int i = 0; i < numstacks; i++)
			{
				FbxAnimStack* pAnimStack = FbxCast<FbxAnimStack>(mScene->GetSrcObject<FbxAnimStack>(i));
				m_AnimStacks.push_back(pAnimStack);
				int layernum = pAnimStack->GetMemberCount<FbxAnimLayer>();
				for (int j = 0; j < layernum; j++)
				{
					FbxAnimLayer *animationlayer = pAnimStack->GetMember<FbxAnimLayer>(i);
					AnimationLayer  *layer = new AnimationLayer();
					m_FBXAnimLayers.push_back(animationlayer);
					m_AnimationLayers.push_back(layer);
				}
				
			}

			//for(int i=0;i<)


			/*	unsigned int posecount = mScene->GetPoseCount();
			unsigned int posecount2 = mScene->GetCharacterPoseCount();
			unsigned int count3 = mScene->GetGeometryCount();
			FbxGeometry* g = mScene->GetGeometry(0);
			g->GetNormals()*/
			//		for (size_t i = 0; i < AnimStackNameArray.Size(); i++)
			//		{
			//			FbxAnimStack *  AnimationStack = mScene->FindMember<FbxAnimStack>(AnimStackNameArray[i]->Buffer());
			//			m_AnimStacks.push_back(AnimationStack);

			//			FbxTimeSpan stackspan = AnimationStack->GetLocalTimeSpan();
			//			SkeletonClip* pose = new SkeletonClip(stackspan.GetDuration().Get(), stackspan.GetDuration().GetFrameCount());
			//			
			//			m_ClipInfos.push_back(stackspan);
			//			m_ClipAsset.push_back(pose);
			///*			FbxTimeSpan stack = AnimationStack->GetLocalTimeSpan();
			//			FbxTime start = AnimationStack->LocalStart;
			//			FbxTime end = AnimationStack->LocalStop;
			//			int a = 1;*/
			//		}

			for (unsigned int i = 0; i < m_AnimStacks.size(); i++)
			{
				FbxAnimLayer * AnimLayer = m_AnimStacks[i]->GetMember<FbxAnimLayer>();
				//if()
			}
		}

		int FBXLoader::GetJointIndex(FbxString jointname)
		{
			//暂时默认，一个fbx只有一个骨骼
			for (int i=0;i<m_SkeletalAsset[0]->joints.size();i++)
			{
			/*	if (m_SkeletalAsset[0]->joints[i]->name.compare(jointname) == 0)
				{
					return i;
				}*/
			}
			return 0;
		}

		joint* FBXLoader::GetJoint(int index)
		{
			return m_SkeletalAsset[0]->joints[index];
		}

	}
}