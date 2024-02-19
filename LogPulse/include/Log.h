#ifndef _log_h_
#define _log_h_

#include "./Date.h"
#include "./String.h"

#include <fstream>
#include <iostream>
using Type::String;
using Utility::Date;

namespace Logging {
	class Log {
	public:
		enum class Level {
			Debug, Info, Warning, Error, Critical
		};

		explicit Log() : m_LogLevel{ Log::Level::Warning }, m_IsFileDumpOn{ false } {};
		Log(const Level& level, const String& filename = "dump.log") : m_LogLevel{level}, m_Filename{filename}, m_IsFileDumpOn{true} {}

		void setLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		Log::Level getLogLevel() const {
			return m_LogLevel;
		}

		void dumpToFile(const String& filename);

		template<typename... Args>
		void critical(const String& message, Args&&... args) const;

		template<typename... Args>
		void error(const String& message, Args&&... args) const;

		template<typename... Args>
		void warn(const String& message, Args&&... args) const;

		template<typename... Args>
		void info(const String& message, Args&&... args) const;

		template<typename... Args>
		void debug(const String& message, Args&&... args) const;

	private:
		void printArgs() const;

		template<typename T, typename... Args>
		void printArgs(T&& arg, Args&&... args) const;

		template<typename... Args>
		void log(const Level& level, const String& message, Args&&... args) const;

		static String getLevelStringColored(const Level& level);
		static String getLevelString(const Level& level);

		Level m_LogLevel;
		String m_Filename;
		bool m_IsFileDumpOn;
		mutable std::ofstream m_OutStream;
	};

	template<typename... Args>
	void Log::critical(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Critical) {
			log(Level::Critical, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::error(const String & message, Args&&... args) const {
		if (m_LogLevel <= Level::Error) {
			log(Level::Error, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::warn(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Warning) {
			log(Level::Warning, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::info(const String & message, Args&&... args) const {
		if (m_LogLevel <= Level::Info) {
			log(Level::Info, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::debug(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Debug) {
			log(Level::Debug, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::log(const Level& level, const String& message, Args&&... args) const {
		if (m_IsFileDumpOn) {
			m_OutStream.open(m_Filename.getRaw(), std::ios::app);

			if (m_OutStream) {
				m_OutStream << Utility::Date::getCurrentDate().getStrDate() << ": [" << getLevelString(level) << "]: " << message << " ";
			}
		}
		std::cout << Utility::Date::getCurrentDate().getStrDate() << ": [" << getLevelStringColored(level) << "]: " << message << " ";
		printArgs(std::forward<Args>(args)...);

		if (m_OutStream.is_open()) {
			m_OutStream.close();
		}
	}

	template<typename T, typename... Args>
	void Log::printArgs(T&& arg, Args&&... args) const {
		if (m_OutStream) {
			m_OutStream << arg << " ";
		}
		std::cout << arg << " ";
		printArgs(std::forward<Args>(args)...);
	}
}



#endif