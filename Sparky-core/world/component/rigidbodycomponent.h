#pragma once
#include "component.h"
#include "maths/mat4.h"
#include "physics/pxShape.h"
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
ComponentType GetType() { return ComponentType::RIGIDBODY_TYPE; }			phyx::ShapeType m_Type;
 
			void PreUpdate()
			{

			 }
			void Update()
			{

			 }
			void PostUpdate()
			{

			 }

#ifdef EDITOR_USE
			void GenerateShape();
#endif
		private:
 
			
			phyx::PxRigidBody *m_RigidBody;
		};

		
	}
}
