#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("String speed");

		std::cout << MYLE::rand_string(10) << std::endl;
	}
}