#include <myle.h>
#include <ostream>


#include "../include/myle_float.h"

int main()
{
	MYLE::Init();

	{
		MYLE::Timer timer("Clamping speed");

		float myFloat = 265.12f;
		MYLE::clamp(myFloat, 200, 250);
		std::cout << myFloat << std::endl;
	}
}
