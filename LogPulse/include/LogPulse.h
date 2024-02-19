#include "Log.h"

namespace LogPulse {
	auto defaultLogger = std::make_shared<Log>("DefaultLogger", Level::Debug, "./logs/default.log");

	std::shared_ptr<Log> getDefaultLogger() {
		return defaultLogger;
	}

	void setDefaultLogger(std::shared_ptr<Log> logPtr) {
		defaultLogger = logPtr;
	}

	template<typename... Args>
	void critical(const String& message, Args&&... args) {
		defaultLogger->critical(message, args...);
	}

	template<typename... Args>
	void error(const String& message, Args&&... args) {
		defaultLogger->error(message, args...);
	}

	template<typename... Args>
	void warn(const String& message, Args&&... args) {
		defaultLogger->warn(message, args...);
	}

	template<typename... Args>
	void debug(const String& message, Args&&... args) {
		defaultLogger->debug(message, args...);
	}

	template<typename... Args>
	void info(const String& message, Args&&... args) {
		defaultLogger->info(message, args...);
	}
}