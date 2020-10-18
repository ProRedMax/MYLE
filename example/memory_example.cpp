#include <myle.h>
#include <ostream>

//Warning: This feature is not yet completed, it could be that unexpected behavior occurs. Use at your own risk.

struct TestStruct
{
	uint32_t testValue = 0;
	float testValue1 = 0.0f;
};

int main()
{
	MYLE::Init();

	MYLE::ResourceManager manager;

	TestStruct* test1;
	TestStruct* test2;
	TestStruct* test3;

	uint32_t blockID = 0;

	{
		MYLE::Timer timer("Memory speed");

		//Allocating a 100 byte big block of memory 
		manager.AllocateMemoryBlock(blockID, 100);

		//Allocating TestStructs
		test1 = manager.AllocateResource<TestStruct>(0, (uint32_t)3, 0.5f);
		test2 = manager.AllocateResource<TestStruct>(0, (uint32_t)5, 1.5f);
		test3 = manager.AllocateResource<TestStruct>(0, (uint32_t)6, 2.5f);
	}

		std::cout << test1->testValue << std::endl;
		std::cout << test1->testValue1 << std::endl;

		std::cout << test2->testValue << std::endl;
		std::cout << test2->testValue1 << std::endl;

		std::cout << test3->testValue << std::endl;
		std::cout << test3->testValue1 << std::endl;
		
		manager.FreeResource(test1);
		manager.FreeResource(test2);
		manager.FreeResource(test3);

		manager.FreeMemoryBlock(blockID);
}
