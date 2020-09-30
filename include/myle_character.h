#pragma once

#include "myle_data.h"

namespace MYLE
{

	/// <summary>
	/// Extracts the numeric value out of the (ASCII) character
	/// </summary>
	/// <param name="c">Character</param>
	/// <returns>Numeric value</returns>
	int numeric_value(char& c);

	//TODO
	//write method
	MYLE::ECHARACTER_TYPE char_type(char& c);

};
