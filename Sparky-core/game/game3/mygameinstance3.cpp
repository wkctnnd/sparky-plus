#include "mygameinstance3.h"
#include "world/component/cameracomponent.h"
#include "world/component/transformcomponent.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "utils/fileutils.h"
#include "Asset/objloader.h"
#include "Asset/AssetLoader.h"
#include "world/scene.h"
#include "world/actor.h"
 
using namespace sparky::render;
using namespace sparky::asset;

using namespace sparky::world;
namespace sparky
{
	namespace game
	{
		void MyGameInstance3::Init()
		{
			AssetLoader assetloader11;
			AssetLoader assetloader12;
			AssetLoader assetloader10;
			AssetLoader assetloader;
			AssetLoader assetloader1;
			AssetLoader assetloader2;
			AssetLoader assetloader3;
			AssetLoader assetloader4;
			AssetLoader assetloader5;
			AssetLoader assetloader6;
			AssetLoader assetloader7;
			AssetLoader assetloader8;
			AssetLoader assetloader9;

			AssetLoader assetloaderlevel0;
			AssetLoader assetloaderlevel1;
			AssetLoader assetloaderlevel2;
			AssetLoader assetloaderlevel3;
			AssetLoader assetloaderlevel4;
			AssetLoader assetloaderlevel5;
			AssetLoader assetloaderlevel6;
			AssetLoader assetloaderlevel7;
			AssetLoader assetloaderlevel8;
			AssetLoader assetloaderlevel9;


			RawMesh* mesh = new RawMesh();

			assetloader10.LoadFile("/model/game/person/01 person/person.obj");
			assetloader1.LoadFile("/model/game/scene1/07 tree/tree.obj");
			assetloader.LoadFile("/model/game/person/02 body/body.obj");
			assetloader2.LoadFile("/model/game/person/03 left_arm/left.obj");
			assetloader3.LoadFile("/model/game/person/04 right_arm/right.obj");


			assetloader4.LoadFile("/model/game/scene1/01 box/box.obj");
			assetloader5.LoadFile("/model/game/scene1/03 floor/floor.obj");
			assetloader6.LoadFile("/model/game/scene1/02 button/button.obj");

			assetloader7.LoadFile("/model/game/scene1/04 left_door/leftdoor.obj");
			assetloader8.LoadFile("/model/game/scene1/05 right door/rightdoor.obj");
			assetloader9.LoadFile("/model/game/scene1/06 wall/wall1.obj");
			assetloader11.LoadFile("/model/game/scene1/06 wall/wall2.obj");
			assetloader12.LoadFile("/model/game/scene1/06 wall/wall3.obj");


			assetloaderlevel0.LoadFile("/model/game/scene2/01 box/box.obj");
			assetloaderlevel1.LoadFile("/model/game/scene2/02 button/button.obj");
			assetloaderlevel2.LoadFile("/model/game/scene2/03 wall/wall.obj");
			assetloaderlevel3.LoadFile("/model/game/scene2/04 left_door/leftdoor.obj");
			assetloaderlevel4.LoadFile("/model/game/scene2/05 right door/rightdoor.obj");
	 
			assetloaderlevel5.LoadFile("/model/game/scene2/06 block/block.obj");
			assetloaderlevel6.LoadFile("/model/game/scene2/07 plane/plane.obj");
			assetloaderlevel7.LoadFile("/model/game/scene2/08 wall2/wall2.obj");
			assetloaderlevel8.LoadFile("/model/game/scene2/09 tree/tree.obj");
		/*	assetloaderlevel10.LoadFile("/model/game/scene1/06 wall/wall2.obj");
			assetloaderlevel11.LoadFile("/model/game/scene1/06 wall/wall3.obj");


			assetloader5.LoadFile("/model/game/scene1/04 left_door/leftdoor.obj");
			assetloader6.LoadFile("/model/game/scene1/05 right door/rightdoor.obj");
			assetloader9.LoadFile("/model/game/scene1/06 wall/wall1.obj");
			assetloader11.LoadFile("/model/game/scene1/06 wall/wall2.obj");
			assetloader12.LoadFile("/model/game/scene1/06 wall/wall3.obj");*/

			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;

			m_BodyResource = assetloader.GetRawStaticMesh(0);
			m_Player = new Player(m_Scene, assetloader10.GetRawStaticMesh(0), assetloader.GetRawStaticMesh(0),assetloader2.GetRawStaticMesh(0),assetloader3.GetRawStaticMesh(0));

			m_Lobby = new Lobby(m_Scene, assetloader5.GetRawStaticMesh(0), assetloader12.GetRawStaticMesh(0), assetloader11.GetRawStaticMesh(0), assetloader9.GetRawStaticMesh(0), assetloader1.GetRawStaticMesh(0), assetloader4.GetRawStaticMesh(0), assetloader6.GetRawStaticMesh(0), assetloader4.GetMaterial(0), assetloader5.GetMaterial(0));
			//m_Lobby2 = new Lobby2(m_Scene, assetloaderlevel0.GetRawStaticMesh(0), assetloaderlevel1.GetRawStaticMesh(0), assetloaderlevel2.GetRawStaticMesh(0), assetloaderlevel3.GetRawStaticMesh(0), assetloaderlevel4.GetRawStaticMesh(0), assetloaderlevel5.GetRawStaticMesh(0), assetloaderlevel6.GetRawStaticMesh(0), assetloaderlevel7.GetRawStaticMesh(0), assetloaderlevel8.GetRawStaticMesh(0), assetloaderlevel0.GetMaterial(0));
			m_LeftDoor = new Door(m_Scene, assetloader7.GetRawStaticMesh(0));
			m_RightDoor = new Door(m_Scene, assetloader8.GetRawStaticMesh(0));
			
			m_Button = new Button(m_Scene, assetloader6.GetRawStaticMesh(0), m_LeftDoor,m_RightDoor,m_Player);
			m_Box = new Box(m_Scene, assetloader4.GetRawStaticMesh(0), assetloader4.GetMaterial(0), float3(37.4, 0.28, 35.5));
			m_Box->GetTransform()->SetLocalPosition(float3(37.4, 0.28, 35.5));
			//m_Lobby->AddBoxColliderActor();
		

		/*	StaticMeshRendererComponent *meshrendercom = (StaticMeshRendererComponent*)m_Player->GetComponent<StaticMeshRendererComponent>();
			RenderMaterial* mat = meshrendercom->GetMaterial(0);
			mat->SetDiffuseColor(float3(1, 0, 0));*/


			Actor* camera = new Actor();
			m_CameraComponent = camera->AddComponent<sparky::world::CameraComponent>();
			m_Player->GetTransform()->Translate(float3(39, 1, 67));
			m_Player->Attach(camera);
			camera->GetTransform()->SetLocalPosition(float3(0, 10, 10));
			/*		m_Player = world::GScene->AddActor();
					sparky::world::StaticMeshRendererComponent* staticmeshcom = m_Player->AddComponent<sparky::world::StaticMeshRendererComponent>();
					int rawsectioncount = assetloader.GetRawStaticMeshCount();


					for (int i = 0; i < rawsectioncount; i++)
					{
						staticmeshcom->AddStaticMesh(assetloader.GetRawStaticMesh(i));
					}
		*/

		/*	staticmeshcom = m_Lobby->AddComponent<sparky::world::StaticMeshRendererComponent>();


			rawsectioncount = assetloader2.GetRawStaticMeshCount();
			for (int i = 0; i < rawsectioncount; i++)
			{
				staticmeshcom->AddStaticMesh(assetloader.GetRawStaticMesh(i));
			}

			staticmeshcom->AddStaticMesh(mesh);*/
		}


		void MyGameInstance3::Update()
		{
			float temp;
	

		}

	}
}