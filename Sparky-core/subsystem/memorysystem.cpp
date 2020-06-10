#include "memorysystem.h"

namespace sparky
{
	namespace subsystem
	{
 
		void MemorySystem::StartUp()
		{
			for (int i = 0; i < 5; i++)
			{
				m_TableInfos[i]->blocksize = 2 << (i + 2);
			}
		
		
		}


		void MemorySystem::ShutDown()
		{

		}
	 
		void* MemorySystem::Allocate(int size)
		{
			int poolid = -1;
			for (int i = 0; i < MAXPOOLCOUNT; i++)
			{
				if (m_TableInfos[i]->blocksize > size)
				{
					if (i > 0)  poolid = i - 1;
					else poolid = 0;
				}
			}

			if (poolid == -1)
			{

			}
			else
			{

			}
			 
		}

		void MemorySystem::Dellocate(void *ptr)
		{

		}
	}
}