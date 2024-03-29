#ifndef _log_h_
#define _log_h_

#include <string>
#include <string_view>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "./Timer.h"

using Util::Timer, std::string, std::string_view;

namespace LogPulse {
	enum class Level {
		Debug, Info, Warning, Error, Critical
	};

	class Log {
	public:
		explicit Log(const string_view& name, const Level& level = Level::Warning) : m_Name{name}, m_LogLevel { level }, m_IsFileDumpOn{ false } {};
		explicit Log(const string_view& name, const Level& level, const std::filesystem::path& filename) : m_Name{ name }, m_LogLevel{level}, m_Filename{filename}, m_IsFileDumpOn{ true } {}

		void setLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		Level getLogLevel() const {
			return m_LogLevel;
		}

		void dumpToFile(const std::filesystem::path& filename);

		template<typename... Args>
		void critical(const string_view& message, Args&&... args) const;

		template<typename... Args>
		void error(const string_view& message, Args&&... args) const;

		template<typename... Args>
		void warn(const string_view& message, Args&&... args) const;

		template<typename... Args>
		void info(const string_view& message, Args&&... args) const;

		template<typename... Args>
		void debug(const string_view& message, Args&&... args) const;

	private:
		void printArgs() const;

		template<typename T, typename... Args>
		void printArgs(T&& arg, Args&&... args) const;

		template<typename... Args>
		void log(const Level& level, const string_view& message, Args&&... args) const;

		static string getLevelStringColored(const Level& level);
		static string getLevelString(const Level& level);

		Level m_LogLevel;
		string m_Name;
		std::filesystem::path m_Filename;
		bool m_IsFileDumpOn;
		mutable std::ofstream m_OutStream;
	};

	template<typename... Args>
	void Log::log(const Level& level, const string_view& message, Args&&... args) const {
		if (m_IsFileDumpOn) {
			m_OutStream.open(m_Filename.string(), std::ios::app);

			if (m_OutStream) {
				m_OutStream << Timer::getCurrentTimeString() << " : [" << m_Name << "] [" << getLevelString(level) << "]: " << message << " ";
			}
		}
		std::cout << Timer::getCurrentTimeString() << " : [" << m_Name << "] [" << getLevelStringColored(level) << "] : " << message << " ";
		printArgs(std::forward<Args>(args)...);

		if (m_OutStream.is_open()) {
			m_OutStream.close();
		}
	}

	template<typename... Args>
	void Log::critical(const string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Critical) {
			log(Level::Critical, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::error(const string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Error) {
			log(Level::Error, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::warn(const string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Warning) {
			log(Level::Warning, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::info(const string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Info) {
			log(Level::Info, message, std::forward<Args>(args)...);
		}
	}

	template<typename... Args>
	void Log::debug(const string_view& message, Args&&... args) const {
		if (m_LogLevel <= Level::Debug) {
			log(Level::Debug, message, std::forward<Args>(args)...);
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