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
    MYLE::init();

    MYLE::log(MYLE::LogLevel::Trace, "%.8e", MYLE::planck);

    MYLE::ResourceManager manager;

    test_struct* test1;
    test_struct* test2;
    test_struct* test3;

    uint32_t block_id = 0;

    {
        MYLE::Timer timer("Memory speed");

        //Allocating a 100 byte big block of memory 
        manager.alloc_memory_block(block_id, 100);

        //Allocating TestStructs
        test1 = manager.alloc_resource<test_struct>(0, (uint32_t)3, 0.5f);
        test2 = manager.alloc_resource<test_struct>(0, (uint32_t)5, 1.5f);
        test3 = manager.alloc_resource<test_struct>(0, (uint32_t)6, 2.5f);
    }

    MYLE::log(MYLE::LogLevel::Trace, "%i", test1->test_value);
    MYLE::log(MYLE::LogLevel::Trace, "%f", test1->test_value1);

    MYLE::log(MYLE::LogLevel::Trace, "%i", test2->test_value);
    MYLE::log(MYLE::LogLevel::Trace, "%f", test2->test_value1);

    MYLE::log(MYLE::LogLevel::Trace, "%i", test3->test_value);
    MYLE::log(MYLE::LogLevel::Trace, "%f", test3->test_value1);

    manager.free_resource(test1);
    manager.free_resource(test2);
    manager.free_resource(test3);

    manager.free_memory_block(block_id);
}
