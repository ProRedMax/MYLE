#pragma once

#include <iostream>

#include <Windows.h>

namespace MYLE {


	enum class LogLevel
	{
		Trace = 0, Info, Warning, Error, Fatal
	};


	template<typename... Args>
	void log(LogLevel level, const std::string& format, Args&&... args)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		std::string output;

		switch (level)
		{
		case LogLevel::Trace:
			SetConsoleTextAttribute(hConsole, 8);
			output = std::string("[TRACE] ").append(format);
			break;
		case LogLevel::Info:
			SetConsoleTextAttribute(hConsole, 2);
			output = std::string("[INFO] ").append(format);
			break;
		case LogLevel::Warning:
			SetConsoleTextAttribute(hConsole, 14);
			output = std::string("[WARNING] ").append(format);
			break;
		case LogLevel::Error:
			SetConsoleTextAttribute(hConsole, 12);
			output = std::string("[ERROR] ").append(format);
			break;
		case LogLevel::Fatal:
			SetConsoleTextAttribute(hConsole, 12);
			output = std::string("[FATAL] ").append(format);
			break;
		}

		std::printf(output.c_str(), std::forward<Args>(args)...);
		std::printf("\n");

		SetConsoleTextAttribute(hConsole, 7);
	}
}
