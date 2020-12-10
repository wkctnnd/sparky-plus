#include "playercontroller.h"
#include "input/input.h"
#include "player.h"
#include "movementcomponent.h"
using namespace sparky::input;
namespace sparky
{
	namespace game
	{

			void PlayerController::Update()
			{
				Player* player = (Player*)(m_Owner);
				MovementComponent *comp = (MovementComponent *)player->GetComponent<MovementComponent>();
				if (Input::GetKey(KEY_W))
				{
					comp->MoveUp();
				}
				else if (Input::GetKey(KEY_S))
				{
					comp->MoveDown();
				}
				else if (Input::GetKey(KEY_A))
				{
					comp->MoveLeft();
				}
				else if (Input::GetKey(KEY_S))
				{
					comp->MoveRight();
				}

				/*RigidBodyComponent* rigidbody = player->GetComponent<RigidBodyComponent>();*/
				
			}	
		 
	}
}
