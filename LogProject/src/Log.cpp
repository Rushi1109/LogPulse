//#include "../include/Log.h"
//using Logging::Log;
//
//void Log::setDate(int dd, int mm, int yy) {
//	m_Date.setDate(dd, mm, yy);
//}
//
//void Log::warn(const String& message) const {
//	if (m_LogLevel >= Log::Level::LevelWarning) {
//		std::cout << m_Date.getStrDate() << ":[Warning] " << message << '\n';
//	}
//}
//
//
//void Log::error(const String& message) const {
//	if (m_LogLevel >= Log::Level::LevelError) {
//		std::cout << m_Date.getStrDate() << ":[Error] " << message << '\n';
//	}
//}
//
//
//void Log::info(const String& message) const {
//	if (m_LogLevel >= Log::Level::LevelInfo) {
//		std::cout << m_Date.getStrDate() << ":[Info] " << message << '\n';
//	}
//}