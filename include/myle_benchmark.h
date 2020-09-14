#pragma once

#include <chrono>
#include <string>
#include <iostream>

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
				std::cout << "Timer " << m_Name << " is already started." << std::endl;
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
				std::cout << "Timer " << m_Name << " is already stopped." << std::endl;
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
				std::cout << "Results of timer " << m_Name << " are currently not available." << std::endl;
				return false;
			}

			std::cout << std::endl;
			std::cout << "Timer: " << m_Name << std::endl;
			std::cout << "	Duration: " << (m_ElapsedTime.count() / 1000.0f) << "ms" << std::endl;
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
