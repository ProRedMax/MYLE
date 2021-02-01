#pragma once
#include <string>

namespace MYLE
{
	class enum_entry
	{
	private:
		std::string name;
	public:

		enum_entry(std::string value)
		{
			name = value;
		}

		std::string getName()
		{
			return name;
		}
		
	};
}



