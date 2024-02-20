#include "./include/Date.h"
#include "./include/Exception.h"
#include "./include/LogPulse.h"
#include<thread>

int main() {
	using LogPulse::Log;
	using LogPulse::Level;

	LogPulse::getDefaultLogger()->setLogLevel(Level::Debug);
	LogPulse::getDefaultLogger()->dumpToFile("./logs/default.log");
	LogPulse::getDefaultLogger()->warn("Debug!!");
	LogPulse::critical("Dead");
	LogPulse::debug("Fine!");
	LogPulse::info("Info", std::this_thread::get_id());
	LogPulse::error("Info", std::this_thread::get_id(), 535, "avxc", 'c');


	Log log("MyLogger");
	log.dumpToFile("./logs/dump.log");
	log.setLogLevel(Level::Debug);
	log.error("Stop!");
	log.warn("Carefull!");
	log.critical("Dead");
	log.debug("Fine!");
	log.info("Info", std::this_thread::get_id());
	log.info("Info", std::this_thread::get_id(), 535, "avxc", 'c');
}