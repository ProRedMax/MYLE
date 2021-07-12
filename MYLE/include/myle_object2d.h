#pragma once
#include <iostream>
#include <myle.h>

#include "myle_identifieable.h"

namespace MYLE
{
	class Object2d : public Identifieable
	{
	public:

		static uint32_t id;

		Object2d();

		Object2d(std::string name, std::string description);

		virtual double area()
		{
			return 0;
		}

		virtual double perimeter()
		{
			return 0;
		}

		std::string to_string();

		inline std::string name()
		{
			return m_Name;
		}

		inline std::string description()
		{
			return m_Description;
		}

		/// <summary>
		/// Overrides the method from the Identieable Interface
		/// </summary>
		/// <returns>mPID</returns>
		virtual uint32_t mPID() override;

	private:

		/// <summary>
		/// Human readable name of the object
		/// </summary>
		std::string m_Name;

		/// <summary>
		/// Describe your figure
		/// </summary>
		std::string m_Description;

		/// <summary>
		/// Myle Public IDentification
		/// </summary>
		uint32_t m_MPID;

	};

};