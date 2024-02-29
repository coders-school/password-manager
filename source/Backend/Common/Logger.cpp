#include "Logger.hpp"

#include <chrono>
#include <format>
#include <memory>
#include <sstream>
#include <vector>

namespace common::logger {

Logger::Logger(const std::string& prefix, const std::string& testName)
    : prefix_(prefix), testName_(testName) {
  std::error_code errorCode;
  std::filesystem::create_directories(logDirectory_, errorCode);
  if (errorCode) {
    std::cerr << "failed to create log directory: " << errorCode.message()
              << std::endl;
    return;
  }

  std::filesystem::path loggingFilePath = logDirectory_ / (testName_ + ".log");
  file_.open(loggingFilePath, std::ios::app);
  if (!file_.is_open()) {
    std::cerr << "unable to open logs file at " << loggingFilePath << std::endl;
  }
}

void Logger::log(const std::string& message) noexcept {
  auto currentTime = std::chrono::system_clock::now();
  auto timeStamp = std::chrono::system_clock::to_time_t(currentTime);
  std::tm timeInfo = *std::localtime(&timeStamp);

  std::stringstream ss;
  ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
  std::string timeStr = ss.str();
  std::vector<std::string> severityVec = {"INFO", "WARNING", "DEBUG", "ERROR"};

  std::string logMessage = std::format(
      "{} [{}][{}]: {}\n", timeStr,
      severityVec[static_cast<int>(currentSeverity_)], prefix_, message);

  file_ << logMessage;
}

Logger& Logger::operator<<(Severity severity) noexcept {
  currentSeverity_ = severity;
  return *this;
}

Logger& Logger::operator<<(const std::string& message) noexcept {
  log(message);
  return *this;
}

}  // namespace common::logger
