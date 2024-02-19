// EMPTY FOR NOW
#include "../include/Log.h"
using Logging::Log;

const String red("\033[0;31m");
const String darkRed("\033[1;31m");
const String yellow("\033[1;33m");
const String cyan("\033[0;36m");
const String magenta("\033[0;35m");
const String reset("\033[0m");

void Log::sinkToFile(const String& filename) {
	m_SinkToFile = true;
	m_Filename = filename;
}

String Log::getLevelStringColored(const Level& level) {
	String strLevel;
	
	switch (level) {
		case Level::Critical : 
			strLevel = darkRed + "Critical" + reset;
			break;

		case Level::Error:
			strLevel = red + "Error" + reset;
			break;

		case Level::Warning:
			strLevel = magenta + "Warning" + reset;
			break;

		case Level::Info:
			strLevel = cyan + "Info" + reset;
			break;

		case Level::Debug:
			strLevel = yellow + "Debug" + reset;
			break;
	}

	return strLevel;
}

String Log::getLevelString(const Level& level) {
	String strLevel;

	switch (level) {
	case Level::Critical:
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