#include <myle.h>

int main()
{
	MYLE::Init();

	{
		MYLE::Timer timer("String speed");

		std::cout << MYLE::rand_string(10) << std::endl;
	}
}