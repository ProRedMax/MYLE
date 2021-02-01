#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("M_ENUM speed");

		MYLE::myle_enum myEnum = MYLE::myle_enum(std::vector<std::string> {"MYLE", "IS", "A", "GREAT", "LIBRARY"});
		
		for (int i = 0; i < 1000; ++i)
		{
			MYLE::enum_entry myName = myEnum.get("MYLE");
			if (myName.getName() == "GREAT")
			{
				unsigned int i = 0;
				i++;
			}
		}
	}


	
	{
		MYLE::Timer timer("Enum speed");

		enum class my_enum { MYLE, IS, A, GREAT, LIBRARY };
		
		for (int i = 0; i < 1000; ++i)
		{	
			if (my_enum::GREAT == my_enum::GREAT)
			{
				unsigned int i = 0;
				i++;
			}
		}

	}

}