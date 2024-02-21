#include "./include/LogPulse.h"
#include<thread>
#include "./include/Timer.h"

int main() {
	using Util::Timer;
	using LogPulse::Log;
	using LogPulse::Level;

	Timer t1;

	LogPulse::getDefaultLogger()->setLogLevel(Level::Debug);
	LogPulse::getDefaultLogger()->dumpToFile("./logs/default.log");
	LogPulse::getDefaultLogger()->warn("Debug!!");
	LogPulse::critical("Dead");
	LogPulse::debug("Fine!");
	LogPulse::info("Info", std::this_thread::get_id());
	LogPulse::error("Info", std::this_thread::get_id(), 535, "avxc", 'c');

	//std::this_thread::sleep_for(std::chrono::seconds{ 4 });

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