#pragma once

#include <memory>

#include <spdlog/logger.h>

namespace spdlog
{
    class logger;
} // namespace spdlog

namespace Logging
{

class Logger final
{
public:

    static void Init();

    static std::shared_ptr<spdlog::logger>& GetLogger() { return m_logger; }


    Logger() = delete;
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    ~Logger() = delete;

    Logger& operator = (const Logger&) = delete;
    Logger& operator = (Logger&&) = delete;

private:
    
    static std::shared_ptr<spdlog::logger> m_logger;
};

}  // namespace Logging

#define LOG_TRACE(...)      Logging::Logger::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)       Logging::Logger::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)       Logging::Logger::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      Logging::Logger::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)   Logging::Logger::GetLogger()->critical(__VA_ARGS__)
