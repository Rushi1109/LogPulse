#include "../include/Log.h"
using LogPulse::Log;

void Log::dumpToFile(const string& filename) {
	m_IsFileDumpOn = true;
	m_Filename = filename;
}

string Log::getLevelStringColored(const Level& level) {
	string strLevel;
	
	switch (level) {
		case Level::Critical : 
			strLevel = "\033[1;31mCritical\033[0m";
			break;

		case Level::Error:
			strLevel = "\033[0;31mError\033[0m";
			break;

		case Level::Warning:
			strLevel = "\033[0;35mWarning\033[0m";
			break;

		case Level::Info:
			strLevel = "\033[0;36mInfo\033[0m";
			break;

		case Level::Debug:
			strLevel = "\033[1;33mDebug\033[0m";
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