#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <filesystem>
#include "time.h"

namespace common::logger
{

enum class Severity
{
    info,
    warning,
    debug,
    error
};

class Logger final
{
public:
    explicit Logger(const std::string& prefix, const std::string& testName = "defaultLogs");
    ~Logger() = default;

    Logger& operator<<(Severity severity) noexcept;
    Logger& operator<<(const std::string& message) noexcept;
private:
    void log(const std::string& message) noexcept;

    std::ofstream file_;
    std::string prefix_;
    std::string testName_;
    Severity currentSeverity_;

    static inline const std::filesystem::path logDirectory_ = "ut_logs/";
};

} // namespace common::logger

constexpr common::logger::Severity info    = common::logger::Severity::info;
constexpr common::logger::Severity warning = common::logger::Severity::warning;
constexpr common::logger::Severity debug   = common::logger::Severity::debug;
constexpr common::logger::Severity error   = common::logger::Severity::error;
