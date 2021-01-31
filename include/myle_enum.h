#pragma once
#include "myle_enum_entry.h"
#include <map>
#include <string>
#include <vector>

namespace MYLE
{
	class myle_enum
	{
	private:
		std::vector<enum_entry> enum_values;
		
	public:

		myle_enum(std::vector<std::string> values)
		{
			for (std::string element : values)
			{
				enum_values.emplace_back(element);
			}
		}

		// TODO Write method
		enum_entry get(std::string entry)
		{
			
		}
		
	};
}
