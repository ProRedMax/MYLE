#include "myle_object2d.h"

namespace MYLE
{
	int object2d::id = 0;

	std::string object2d::to_string()
	{
		return "Your " + get_name() + " has an area of: " + std::to_string(get_area()) + " and a perimeter of: " + 
			std::to_string(get_perimeter()) + "; \nDescription: " + get_description();
	}

	uint32_t object2d::get_mPID()
	{
		return mPID;
	}

	object2d::object2d()
	{
		prefix = 000;
		this->name = "MyObject";
		this->description = "My Description";
		Identifieable::make_mPID(id);
		id++;
	}

	object2d::object2d(std::string name, std::string description)
	{
		object2d();
		this->name = name;
		this->description = description;
	}

}



