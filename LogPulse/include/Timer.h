#ifndef _Timer_h_
#define _Timer_h_

#include <chrono>
#include <iostream>

namespace Util {
	class Timer {
	public:
		Timer() : m_Start{std::chrono::high_resolution_clock::now()} {}

		void timeElapsed() {
			auto m_End = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_End - m_Start);
			auto ms = duration;
			std::cout << ms.count() << "ms\n";
		}

		static std::string getCurrentTimeString() {
			auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			std::tm timeBuffer;
			localtime_s(&timeBuffer, &currentTime);
			char buffer[18];
			strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", &timeBuffer);
			return buffer;
		}

		~Timer() {
			timeElapsed();
		}

	private:
		std::chrono::high_resolution_clock::time_point m_Start;
	};
}

#endif // !_Timer_h_
