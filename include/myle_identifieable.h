#pragma once

#include <iostream>

class Identifieable
{
public:

	/// <summary>
	/// Three digit prefix to generate the mPID
	/// </summary>
	uint16_t m_Prefix;

	virtual uint32_t mPID() = 0;

	uint32_t make_mPID(int id)
	{
		std::string number = std::to_string(m_Prefix) + std::to_string(id);

		return std::stoi(number);
	}

};