#pragma once

#include <iostream>

class Identifieable
{
public:

	/// <summary>
	/// Three digit prefix to generate the mPID
	/// </summary>
	int prefix;

	virtual uint32_t get_mPID() = 0;

	uint32_t make_mPID(int id)
	{
		std::string number = std::to_string(prefix) + std::to_string(id);
		return std::stoi(number);
	}

};