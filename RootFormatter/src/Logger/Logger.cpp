#include "Logger.h"

#include <memory>
#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

namespace Logging
{

std::shared_ptr<spdlog::logger> Logger::m_logger;

void Logger::Init()
{
    using spdlog::sinks::basic_file_sink_mt;
    // TODO(4rtemTrickster): Add normal place and settings for logs
    std::shared_ptr<basic_file_sink_mt> file_sink = std::make_shared<basic_file_sink_mt>(R"(RF.log)", true);
    file_sink->set_pattern("%^[%T] [%l]: %v%$");

    m_logger = std::make_shared<spdlog::logger>("Logger", file_sink);

    spdlog::register_logger(m_logger);

    m_logger->set_level(spdlog::level::trace);
    m_logger->flush_on(spdlog::level::trace);

    LOG_TRACE("Logger initialized");
}

} // namespace Logging
