#include <myle_algorithm.h>

#include <iostream>

int main()
{
	std::string number = "535685728819377";
	std::cout << "Luhn sum for" << number <<" is: " << MYLE::luhn_checksum(number) << std::endl;
	if (MYLE::luhn(number + std::to_string(MYLE::luhn_checksum(number))))
	{
		std::cout << number << " passes the luhn algorithm!" << std::endl;
	}
	else
	{
		std::cout << number << " failed  the luhn algorithm!" << std::endl;
	}
}