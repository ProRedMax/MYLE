#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("Luhn speed");

		std::string luhn_number = MYLE::generate_luhn(20);

		MYLE::log(MYLE::LogLevel::Trace, "Generated luhn number is %s", luhn_number.c_str());

		std::string number = luhn_number.substr(0, luhn_number.size() - 1);

		MYLE::log(MYLE::LogLevel::Trace, "Luhn sum for %s is: %i", number.c_str(), MYLE::luhn_checksum(number));

		if (MYLE::luhn(luhn_number))
		{
			MYLE::log(MYLE::LogLevel::Info, "%s passed the luhn algorithm!", luhn_number.c_str());
		}
		else
		{
			MYLE::log(MYLE::LogLevel::Error, "%s failed the luhn algorithm!", luhn_number.c_str());
		}
	}
}