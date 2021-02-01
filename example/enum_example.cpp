#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("M_ENUM speed");

		MYLE::myle_enum myEnum = MYLE::myle_enum(std::vector<std::string> {"MYLE", "IS", "A", "GREAT", "LIBRARY"});

		std::cout << myEnum.get("MYLE").getName();
		
		
	}
}