#include <myle.h>
#include <ostream>

//Warning: This feature is not yet completed, it could be that unexpected behavior occurs. Use at your own risk.

struct test_struct
{
    uint32_t test_value = 0;
    float test_value1 = 0.0f;
};

int main()
{
    MYLE::Init();

    std::cout << MYLE::plank << std::endl;

    MYLE::ResourceManager manager;

    test_struct* test1;
    test_struct* test2;
    test_struct* test3;

    uint32_t block_id = 0;

    {
        MYLE::Timer timer("Memory speed");

        //Allocating a 100 byte big block of memory 
        manager.AllocateMemoryBlock(block_id, 100);

        //Allocating TestStructs
        test1 = manager.AllocateResource<test_struct>(0, (uint32_t)3, 0.5f);
        test2 = manager.AllocateResource<test_struct>(0, (uint32_t)5, 1.5f);
        test3 = manager.AllocateResource<test_struct>(0, (uint32_t)6, 2.5f);
    }

    std::cout << test1->test_value << std::endl;
    std::cout << test1->test_value1 << std::endl;

    std::cout << test2->test_value << std::endl;
    std::cout << test2->test_value1 << std::endl;

    std::cout << test3->test_value << std::endl;
    std::cout << test3->test_value1 << std::endl;

    manager.FreeResource(test1);
    manager.FreeResource(test2);
    manager.FreeResource(test3);

    manager.FreeMemoryBlock(block_id);
}
