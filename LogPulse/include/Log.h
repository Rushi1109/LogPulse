#ifndef _log_h_
#define _log_h_

#include "./Date.h"
#include "./String.h"

namespace Logging {
	class Log {
	public:
		enum class Level {
			LevelError, LevelWarning, LevelInfo
		};

		explicit Log() : m_LogLevel{ Log::Level::LevelInfo }, m_Date{} {};


		void setLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		Log::Level getLogLevel() const {
			return m_LogLevel;
		}

		void setDate(int dd, int mm, int yy) {
			m_Date.setDate(dd, mm, yy);
		}

		template<typename... Args>
		void warn(const String& message, Args&&... args) const;

		template<typename... Args>
		void error(const String& message, Args&&... args) const;

		template<typename... Args>
		void info(const String& message, Args&&... args) const;

	private:
		Level m_LogLevel;
		Utility::Date m_Date;


		void printArgs() const;

		template<typename T, typename... Args>
		void printArgs(T&& arg, Args&&... args) const;
	};

	template<typename... Args>
	void Log::warn(const String& message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelWarning) {
			std::cout << m_Date.getStrDate() << ": [Warning] " << message << " ";
		}
		printArgs(args...);
	}

	template<typename... Args>
	void Log::error(const String & message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelError) {
			std::cout << m_Date.getStrDate() << ": [Error] " << message << " ";
		}
		printArgs(args...);
	}

	template<typename... Args>
	void Log::info(const String & message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelInfo) {
			std::cout << m_Date.getStrDate() << ": [Info] " << message << " ";
		}
		printArgs(args...);
	}

	template<typename T, typename... Args>
	void Log::printArgs(T&& arg, Args&&... args) const {
		std::cout << arg << " ";
		printArgs(args...);
	}


	void Log::printArgs() const {
		std::cout << std::endl;
	};
}



#endif