#pragma once

#include "../data/myle_data.h"

namespace MYLE
{

	/// <summary>
	/// Extracts the numeric value out of the (ASCII) character
	/// </summary>
	/// <param name="c">Character</param>
	/// <returns>Numeric value</returns>
	int getNumericValue(char& c);

	//TODO
	//write method
	MYLE::ECHARACTER_TYPE getCharacterType(char& c);

};
