// EMPTY FOR NOW
#include "../include/Log.h"
using LogPulse::Log;

const string red("\033[0;31m");
const string darkRed("\033[1;31m");
const string yellow("\033[1;33m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string reset("\033[0m");

void Log::dumpToFile(const string& filename) {
	m_IsFileDumpOn = true;
	m_Filename = filename;
}

string Log::getLevelStringColored(const Level& level) {
	string strLevel;
	
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

string Log::getLevelString(const Level& level) {
	string strLevel;

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