#ifndef _LogPulse_h_
#define _LogPulse_h_

#include "./Log.h"
#include "./Registry.h"

namespace LogPulse {
	inline std::shared_ptr<Log> getDefaultLogger() {
		return Registry::instance().getDefaultLogger();
	}

	inline void setDefaultLogger(std::shared_ptr<Log> logPtr) {
		Registry::instance().setDefaulatLogger(logPtr);
	}

	template<typename... Args>
	void critical(const string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->critical(message, args...);
	}

	template<typename... Args>
	void error(const string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->error(message, args...);
	}

	template<typename... Args>
	void warn(const string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->warn(message, args...);
	}

	template<typename... Args>
	void info(const string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->info(message, args...);
	}

	template<typename... Args>
	void debug(const string_view& message, Args&&... args) {
		Registry::instance().getDefaultLogger()->debug(message, args...);
	}
}

#endif