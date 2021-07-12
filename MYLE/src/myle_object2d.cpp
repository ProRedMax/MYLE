#include "myle_object2d.h"

namespace MYLE
{
	uint32_t Object2d::id = 0;

	Object2d::Object2d()
	{
		m_Prefix = 100;
		m_Name = "MyObject";
		m_Description = "My Description";
		Identifieable::make_mPID(id);
		id++;
	}

	Object2d::Object2d(std::string name, std::string description)
		: Object2d()
	{
		m_Name = name;
		m_Description = description;
	}

	std::string Object2d::to_string()
	{
		return "Your " + name() + " has an area of: " + std::to_string(area()) + " and a perimeter of: " + 
			std::to_string(perimeter()) + "; \nDescription: " + description();
	}

	uint32_t Object2d::mPID()
	{
		return m_MPID;
	}
}



