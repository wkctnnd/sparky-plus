#include "PxSoftBody.h"

namespace sparky
{
	namespace phyx
	{
		void init_mass(PxSoftBody * softbody, double mass, double length, double X, double Y, double Z, int indexc)
		{
		/*	softbody->AddMass(mass, float3(0, 0, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));

			softbody->AddMass(mass, float3(X + length, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + 2 * length, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + 2 * length, Z), float3(0, 0, 0), float3(0, 0, 0));


			softbody->AddMass(mass, float3( X + 2 * length,Y + 2 * length,Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y, Z + length), float3(0, 0, 0), float3(0, 0, 0));


			softbody->AddMass(mass, float3(X, Y + length, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + length, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y + length, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + 2 * length, Z + length), float3(0, 0, 0), float3(0, 0, 0));


			softbody->AddMass(mass, float3(X + length, Y + 2 * length, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y + 2 * length, Z + length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));

			softbody->AddMass(mass, float3(X + 2 * length, Y, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y + length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));

			softbody->AddMass(mass, float3(X, Y + 2 * length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + 2 * length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + 2 * length, Y + 2 * length, Z + 2 * length), float3(0, 0, 0), float3(0, 0, 0));
*/
			//front
			softbody->AddMass(mass, float3(0, 0, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, 0), float3(0, 0, 0), float3(0, 0, 0));		
			softbody->AddMass(mass, float3(X + length, Y + length, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, 0), float3(0, 0, 0), float3(0, 0, 0));

			//back
			softbody->AddMass(mass, float3(0, 0, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));


		}

		void init_spring(PxSoftBody* softbody,float k, float length) 
		{
			softbody->AddSpring(k, length, 0, 1);
			softbody->AddSpring(k, length, 1, 2);
			softbody->AddSpring(k, length, 2, 3);
			softbody->AddSpring(k, length, 3, 0);

			softbody->AddSpring(k, length, 0, 4);
			softbody->AddSpring(k, length, 4, 7);
			softbody->AddSpring(k, length, 7, 3);

			softbody->AddSpring(k, length, 1, 5);
			softbody->AddSpring(k, length, 5, 6);
			softbody->AddSpring(k, length, 2, 6);
		 

			softbody->AddSpring(k, length, 4, 5);
			softbody->AddSpring(k, length, 6, 7);
			
			 
		}

	

		 

		 PxSoftBody* PxSoftBody::CreateDefaultCube(int c)
		{
			double originalx = 0;
			double originaly = 0;
			double originalz = 10;

			PxSoftBody * body = new PxSoftBody();
			init_mass(body, 0.2, 10, originalx, originaly, originalz, c);
			init_spring(body, 20, 10);
			return body;
			
		}

		 void PxSoftBody::ApplyForce(std::vector<Force>& forces)
		 {
			 for (int i=0;i<forces.size();i++)
			 {
				 Mass* forcemass = FindNearestMass(forces[i].position);

			 }
		 }

		 void PxSoftBody::Update(float time)
		 {
			 for (int i=0;i<m_Spring.size();i++)
			 {
				 m_Spring[i]->len = m_Spring[i]->oriL+sin(time);
			 }
		 }


		 void PxSoftBody::Simulate(float time)
		 {
			 time /= 1000;
			 //更新spring的tension力
			 for (int i=0;i<m_Spring.size();i++)
			 {
				 float3 tensionvec = m_Mass[m_Spring[i]->m1]->pos - m_Mass[m_Spring[i]->m2]->pos;
				 float len = tensionvec.length() - m_Spring[i]->len;
				
				 float tensionforce;
			 
					 tensionforce = m_Spring[i]->k*len / m_Spring[i]->len;
			 
				 m_Spring[i]->force = tensionvec.Normalize()*tensionforce;
			 }

			 //更新mass受到的力
			 for (int i=0;i<m_Mass.size();i++)
			 {
				float3 force(0, 0, 0);
				  for (int j = 0; j < m_Mass[i]->Springs.size(); j++)
				 {
					  if (m_Mass[i]->Springs[j]->force.length() != 0)
					  {
						  if (i == m_Mass[i]->Springs[j]->m1)
						  {
							  force += m_Mass[i]->Springs[j]->force * -1;
						  }
						  else
						  {
							  force += m_Mass[i]->Springs[j]->force;
						  }
					  }
				
					
				 }
				 force.y += m_Grvavity*m_Mass[i]->mass;

				 m_Mass[i]->acc = force / m_Mass[i]->mass;
				 m_Mass[i]->nextvec = (m_Mass[i]->vec + m_Mass[i]->acc*time)*0.95;
				 m_Mass[i]->nextpos = m_Mass[i]->pos + (m_Mass[i]->vec + m_Mass[i]->nextvec) / 2 * time;
				 
			 }
			 float3 temp(0, 0, 0);
			 for (int i = 0; i < m_Mass.size(); i++)
			 {
				 
				 temp += m_Mass[i]->acc - float3(0,m_Grvavity,0);
				
			 }
			 if (temp.length() >0.001)
			 {
				 int a = 1;
			 }
			 //碰撞地面

			 //交换
			 for (int i = 0; i < m_Mass.size(); i++)
			 {
 
				 m_Mass[i]->vec = m_Mass[i]->nextvec + m_Mass[i]->acc*time;
				 m_Mass[i]->pos = m_Mass[i]->nextpos;

				 if (m_Mass[i]->pos.y < m_Ground)
				 {
					 m_Mass[i]->pos.y = m_Ground;
					 m_Mass[i]->vec = m_Mass[i]->vec*-1;
				 }
			 }
		 }

		 void PxSoftBody::AddMass(float mass, float3 pos, float3 vec, float3 acc)
		 {
			 m_Mass.push_back(new Mass(mass, pos, vec, acc));
		 }


		 void PxSoftBody::AddSpring(float k, float len, int m1, int m2)
		 {
			 m_Spring.push_back(new Spring(k, len, m1, m2));
			 m_Mass[m1]->Springs.push_back(m_Spring[m_Spring.size() - 1]);
			 m_Mass[m2]->Springs.push_back(m_Spring[m_Spring.size() - 1]);
		 }

		 //应该也许可以使用kd-tree加速
		 Mass* PxSoftBody::FindNearestMass(float3 position)
		 {
			 float neardis=100000;
			 Mass* res = 0;
			 for (int i = 0; i < m_Mass.size(); i++)
			 {
				 float3 tempvec = m_Mass[i]->pos - position;
				 float templength = tempvec.length();
				 if (templength<neardis)
				 {
					 res = m_Mass[i];
					 neardis = templength;
				 }
			 }
			 return res;
		 }

		 void PxSoftBody::GetRenderData(std::vector<float3> &vertexarray)
		 {

		 }
	}
}