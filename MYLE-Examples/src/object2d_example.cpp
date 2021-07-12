#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("Object2D speed");

		MYLE::Object2d myObject("Test1", "Description test");

		MYLE::log(MYLE::LogLevel::Trace, "%s", myObject.to_string().c_str());
		MYLE::log(MYLE::LogLevel::Trace, "%zu", myObject.mPID());
	}
}