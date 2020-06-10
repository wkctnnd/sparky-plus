#pragma once
#include "subsystem.h"
#define  MAXPOOLCOUNT 5
namespace sparky
{
	namespace subsystem
	{
		struct FreeMemory
		{
			void* Next;
			int count;
		};

		struct BlockInfo
		{
			class TableInfo* owner;
			FreeMemory* freememory;
			BlockInfo* NextBlock;
		};

		struct TableInfo
		{
			BlockInfo *FullPoolEntry;
			BlockInfo *FreePoolEntry;
			int blocksize;
		};




		class MemorySystem :public ISubSystem
		{
		public:
			void StartUp();
			void ShutDown();

			void* Allocate(int size);
			void Dellocate(void *ptr);

		private:
			TableInfo* m_TableInfos[MAXPOOLCOUNT];

		};
	}
}
