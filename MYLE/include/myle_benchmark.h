#pragma once

#include <chrono>
#include <string>
#include <iostream>

#include "myle_console.h"

namespace MYLE {

	class Timer
	{
	public:

		Timer(const std::string& name)
			: m_Name(name), m_Active(false)
		{
			StartTimer();
		}

		~Timer()
		{
			if (m_Active)
			{
				StopTimer();
				PrintResults();
			}
		}

		bool StartTimer()
		{
			if (m_Active)
			{
				log(LogLevel::Error, "Timer %s is already started.", m_Name.c_str());
				return false;
			}

			m_Start = std::chrono::high_resolution_clock::now();

			m_Active = true;

			return true;
		}

		bool StopTimer()
		{
			if (!m_Active)
			{
				log(LogLevel::Error, "Timer %s is already stopped.", m_Name.c_str());
				return false;
			}

			m_End = std::chrono::high_resolution_clock::now();

			m_ElapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_End).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_Start).time_since_epoch();

			m_Active = false;

			return true;
		}

		bool PrintResults()
		{
			if (m_Active)
			{
				log(LogLevel::Error, "Results of timer %s are currently not available.", m_Name.c_str());
				return false;
			}

			std::cout << std::endl;

			log(LogLevel::Info, "Timer: %s", m_Name.c_str());
			log(LogLevel::Info, "	Duration: %fms", m_ElapsedTime.count() / 1000.0f);

			std::cout << std::endl;

			return true;
		}

	private:
		std::string m_Name;
		bool m_Active;

		std::chrono::time_point<std::chrono::steady_clock> m_Start;
		std::chrono::time_point<std::chrono::steady_clock> m_End;

		std::chrono::microseconds m_ElapsedTime;
	};


};
