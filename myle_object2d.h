#pragma once
#include <iostream>
#include <myle.h>
#include "Identifieable.h"

namespace MYLE
{
	class object2d : public Identifieable
	{
	public:

		static int id;

		object2d();

		object2d(std::string name, std::string description);

		virtual double get_area()
		{
			return 0;
		}

		virtual double get_perimeter()
		{
			return 0;
		}

		std::string to_string();

		inline std::string get_name()
		{
			return name;
		}

		inline std::string get_description()
		{
			return description;
		}

		/// <summary>
		/// Overrides the method from the Identieable Interface
		/// </summary>
		/// <returns>mPID</returns>
		virtual uint32_t get_mPID() override;

	private:

		/// <summary>
		/// Human readable name of the object
		/// </summary>
		std::string name;

		/// <summary>
		/// Descriibe your figure
		/// </summary>
		std::string description;

		/// <summary>
		/// Myle Public IDentification
		/// </summary>
		uint32_t mPID;

	};

};