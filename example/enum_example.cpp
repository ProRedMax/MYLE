#include <myle.h>

int main()
{
	MYLE::init();

	{
		MYLE::Timer timer("M_ENUM speed");
		enum class my_enum { MYLE, IS, A, GREAT, LIBRARY };	
		
	}


	
	{
		MYLE::Timer timer("Enum speed");

		enum class my_enum { MYLE, IS, A, GREAT, LIBRARY };
		
		
		for (int i = 0; i < 1; ++i)
		{
			my_enum hallo = static_cast<my_enum>(MYLE::rand_int(0, 3, false));
			
			if (hallo == my_enum::GREAT)
			{
				unsigned int i = 0;
				i++;
			}
		}
	}
}