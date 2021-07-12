#include <myle.h>
#include <ostream>

#include <myle_float.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("Clamping speed");

		float myFloat = 265.12f;
		MYLE::clamp(myFloat, 200, 250);

		MYLE::log(MYLE::LogLevel::Trace, "%f", myFloat);
	}
}
