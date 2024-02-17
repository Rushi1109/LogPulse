#include "./include/Log.h"

#include "./include/Date.h"

#include "./include/String.h"

#include "./include/Exception.h"

int main() {
	using Logging::Log;
	using Utility::Date;
	Log log;

	log.setLogLevel(Log::Level::LevelInfo);
	log.setDate(30, 01, 2024);
	log.error("Stop!");
	log.warn("Carefull!");
	log.info("Fine!");
	log.setDate(23, 9, 2022);
	log.info("Hello", 2342, 2,3,3,535);
	log.info("Hello", 2342, 2, 3, 3, 535, "avxc", 'c');
	log.warn("Carefull!");
	log.warn("Carefull!");
}