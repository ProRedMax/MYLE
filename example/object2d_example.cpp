#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("Object2D speed");

		MYLE::Object2d myObject("Test1", "Description test");

		std::cout << myObject.to_string() << std::endl;
		std::cout << myObject.mPID() << std::endl;

	}
}