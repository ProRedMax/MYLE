#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("String speed");

		MYLE::log(MYLE::LogLevel::Trace, "%s", MYLE::rand_string(10).c_str());
	}
}