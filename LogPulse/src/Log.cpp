// EMPTY FOR NOW
#include "../include/Log.h"
using Logging::Log;

void Log::sinkToFile(const String& filename) {
	m_SinkToFile = true;
	m_Filename = filename;
}

String Log::getLevelString(const Level& level) {
	String strLevel;
	
	switch (level) {
		case Level::Critical : 
			strLevel = "Critical";
			break;

		case Level::Error:
			strLevel = "Error";
			break;

		case Level::Warning:
			strLevel = "Warning";
			break;

		case Level::Info:
			strLevel = "Info";
			break;

		case Level::Debug:
			strLevel = "Debug";
			break;
	}

	return strLevel;
}

void Log::printArgs() const {
	if (m_OutStream) {
		m_OutStream << std::endl;
	}
	std::cout << std::endl;
};