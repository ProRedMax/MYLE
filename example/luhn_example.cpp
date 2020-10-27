#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("Luhn speed");

		std::string luhn_number = MYLE::generate_luhn(20);

		std::cout << "Generated luhn number is " << luhn_number << std::endl;

		std::string number = luhn_number.substr(0, luhn_number.size() - 1);
		
		std::cout << "Luhn sum for " << number << " is: " << MYLE::luhn_checksum(number) << std::endl;

		if (MYLE::luhn(luhn_number))
		{
			std::cout << luhn_number << " passes the luhn algorithm!" << std::endl;
		}
		else
		{
			std::cout << luhn_number << " failed  the luhn algorithm!" << std::endl;
		}
	}
}