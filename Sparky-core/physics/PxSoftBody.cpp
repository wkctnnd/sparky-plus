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
			softbody->AddMass(mass, float3(0, Y, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + length, 0), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, 0), float3(0, 0, 0), float3(0, 0, 0));

			//back
			softbody->AddMass(mass, float3(0, Y, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X + length, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));
			softbody->AddMass(mass, float3(X, Y + length, Z), float3(0, 0, 0), float3(0, 0, 0));


		}

		void init_spring(PxSoftBody* softbody,float ks, float kd, float length) 
		{
			softbody->AddSpring(ks, kd, length, 0, 1);
			softbody->AddSpring(ks, kd, length, 1, 2);
			softbody->AddSpring(ks, kd, length, 2, 3);
			softbody->AddSpring(ks, kd, length, 3, 0);

			softbody->AddSpring(ks, kd, length, 0, 4);
			softbody->AddSpring(ks, kd, length, 4, 7);
			softbody->AddSpring(ks, kd, length, 7, 3);

			softbody->AddSpring(ks, kd, length, 5, 6);
			softbody->AddSpring(ks, kd, length, 1, 5);
			softbody->AddSpring(ks, kd, length, 2, 6);
		 

			softbody->AddSpring(ks, kd, length, 4, 5);
			softbody->AddSpring(ks, kd, length, 6, 7);
			
			 
		}

	

		 

		 PxSoftBody* PxSoftBody::CreateDefaultCube(int c)
		{
			double originalx = 0;
			double originaly = 10;
			double originalz = 10;

			PxSoftBody * body = new PxSoftBody(0);
			init_mass(body, 0.01, 10, originalx, originaly, originalz, c);
			init_spring(body, 20, 0.03, 10);
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
				 m_Spring[i]->len = m_Spring[i]->oriL + sin(time/10000);
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
				 if (abs(len) < 0.0001) len = 0;
				 if (len < 0)
				 {
					 int a = 0;
				 }
				 float tensionforce;
			 
				 tensionforce = m_Spring[i]->ks*len / m_Spring[i]->len;
					
				 m_Spring[i]->force = tensionvec.Normalize()*tensionforce;

				// m_Spring[i]->damping = (m_Mass[m_Spring[i]->m1]->vec - m_Mass[m_Spring[i]->m2]->vec).Dot(tensionvec.Normalize());
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
							  float3 springvec = (m_Mass[m_Mass[i]->Springs[j]->m1]->pos - m_Mass[m_Mass[i]->Springs[j]->m2]->pos).Normalize();
							  float3 dampforce = springvec * ((m_Mass[m_Mass[i]->Springs[j]->m1]->vec - m_Mass[m_Mass[i]->Springs[j]->m2]->vec).Dot(springvec))*-1 * m_Spring[j]->kd;
							  if (abs(dampforce.x) < 0.00001)dampforce.x = 0;
							  if (abs(dampforce.y) < 0.00001)dampforce.y = 0;
							  if (abs(dampforce.z) < 0.00001)dampforce.z = 0;
							  force += m_Mass[i]->Springs[j]->force * -1 + dampforce;
						  }
						  else
						  {
							  float3 springvec = (m_Mass[m_Mass[i]->Springs[j]->m2]->pos - m_Mass[m_Mass[i]->Springs[j]->m1]->pos).Normalize();
							  float3 dampforce = springvec * ((m_Mass[m_Mass[i]->Springs[j]->m2]->vec - m_Mass[m_Mass[i]->Springs[j]->m1]->vec).Dot(springvec))*-1 * m_Spring[j]->kd;
							  if (abs(dampforce.x) < 0.00001)dampforce.x = 0;
							  if (abs(dampforce.y) < 0.00001)dampforce.y = 0;
							  if (abs(dampforce.z) < 0.00001)dampforce.z = 0;
							  force += m_Mass[i]->Springs[j]->force + dampforce;
						  }
					  }
				
					
				 }

				  force  = force* 0.7;
				 force.y += m_Grvavity*m_Mass[i]->mass;

				 m_Mass[i]->acc = force / m_Mass[i]->mass;
				 float3 temp = (m_Mass[i]->vec + m_Mass[i]->acc*time) ;
				 m_Mass[i]->nextvec = m_Mass[i]->vec;
				 if (abs(m_Mass[i]->vec.x - temp.x) > 0.0001)
					 m_Mass[i]->nextvec.x = temp.x;
				 if (abs(m_Mass[i]->vec.y - temp.y) > 0.0001)
					 m_Mass[i]->nextvec.y = temp.y;
				 if (abs(m_Mass[i]->vec.z - temp.z) > 0.0001)
					 m_Mass[i]->nextvec.z = temp.z;


				 m_Mass[i]->nextpos = m_Mass[i]->pos + (m_Mass[i]->vec + m_Mass[i]->nextvec) / 2 * time;
				 
			 }

			 for (int i = 0; i< m_Mass.size(); i++)
			 {
				 std::cout << m_Mass[i]->acc.x<<" "<<m_Mass[i]->acc.y<<" "<<m_Mass[i]->acc.z<<"\n";
			 }
			 std::cout << "\n\n\n\n";
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
				
				 if(abs(m_Mass[i]->vec. x- m_Mass[i]->nextvec.x)>0.0001) 
					 m_Mass[i]->vec.x = m_Mass[i]->nextvec.x;
				 if (abs(m_Mass[i]->vec.y - m_Mass[i]->nextvec.y) > 0.0001)
					 m_Mass[i]->vec.y = m_Mass[i]->nextvec.y;
				 if (abs(m_Mass[i]->vec.z - m_Mass[i]->nextvec.z) > 0.0001)
					 m_Mass[i]->vec.z = m_Mass[i]->nextvec.z;

				 if (abs(m_Mass[i]->pos.x - m_Mass[i]->nextpos.x) > 0.0001)
					 m_Mass[i]->pos.x = m_Mass[i]->nextpos.x;
				 if (abs(m_Mass[i]->pos.y - m_Mass[i]->nextpos.y) > 0.0001)
					 m_Mass[i]->pos.y = m_Mass[i]->nextpos.y;
				 if (abs(m_Mass[i]->pos.z - m_Mass[i]->nextpos.z) > 0.0001)
					 m_Mass[i]->pos.z = m_Mass[i]->nextpos.z;

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


		 void PxSoftBody::AddSpring(float ks, float kd, float len, int m1, int m2)
		 {
			 m_Spring.push_back(new Spring(ks, kd, len, m1, m2));
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