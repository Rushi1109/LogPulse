#include "./include/Date.h"
#include <string>
#include "./include/Exception.h"
#include "./include/LogPulse.h"
#include<thread>

int main() {
	using LogPulse::Log;
	using Utility::Date;
	using LogPulse::Level;

	Log log("MyLogger");

	LogPulse::getDefaultLogger()->warn("Debug!!");
	LogPulse::critical("Dead");
	LogPulse::info("Fine!");
	LogPulse::info("Info", std::this_thread::get_id());
	LogPulse::info("Info", std::this_thread::get_id(), 535, "avxc", 'c');

	log.dumpToFile("./logs/dump.log");
	// log.setLogLevel(Level::Debug);
	log.error("Stop!");
	log.warn("Carefull!");
	log.critical("Dead");
	log.info("Fine!");
	log.info("Info", std::this_thread::get_id());
	log.info("Info", std::this_thread::get_id(), 535, "avxc", 'c');
	log.warn("Carefull!");
	log.debug("Debug");
	log.warn("Warning!");
}