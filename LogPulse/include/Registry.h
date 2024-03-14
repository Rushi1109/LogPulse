#ifndef _registry_h_
#define _registry_h_

#include<iostream>
#include "./Log.h"

namespace LogPulse {
	class Registry {
	public:
		std::shared_ptr<Log> getDefaultLogger() const {
			return defaultLogger;
		}

		void setDefaulatLogger(std::shared_ptr<Log> logger) {
			defaultLogger = logger;
		}

		static Registry& instance() {
			static Registry registry;
			return registry;
		}

	private:
		Registry() : defaultLogger{ std::make_shared<Log>("DefaultLogger") } {}
		~Registry() = default;

		std::shared_ptr<Log> defaultLogger;
	};
}

#endif
