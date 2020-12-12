#pragma once
#include "component.h"
#include "maths/mat4.h"
#include "physics/pxShape.h"
#include "physics/PxRigidBody.h"
#include "world/actor.h"
using namespace sparky::maths;
namespace sparky
{
	namespace phyx
	{
		//class PxShape;
		class PxRigidBody;
	}
	namespace world
	{
		class RigidBodyComponent :public Component
		{
		public:
			static ComponentType TYPE;
			RigidBodyComponent(Actor *owner) :Component(owner) {};
			ComponentType GetType() { return ComponentType::RIGIDBODY_TYPE; }	
			void GenerateShape(class asset::RawMesh* mesh, class world::ScriptComponent* component, phyx::ShapeType type);
			//phyx::ShapeType m_Type;
 
			void PreUpdate()
			{

			 }
			void Update()
			{

			 }
			void PostUpdate()
			{

			 }

			phyx::PxRigidBody * GetRigidBody() 
			{ 
				if(m_Owner->IsActive())
					return m_RigidBody;
				return 0;
			}
//#ifdef EDITOR_USE
//			void GenerateShape();
//#endif
		private:
 
			
			phyx::PxRigidBody *m_RigidBody;
		};

		
	}
}
