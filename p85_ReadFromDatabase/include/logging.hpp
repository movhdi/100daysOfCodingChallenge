
#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <boost/current_function.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/log/attributes/attribute_set.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/exception.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/throw_exception.hpp>
#include <exception>
#include <string>

enum severity_level {
    verbose,
    debug,
    info,
    warning,
    error,
    critical,
};

void init(const std::string& logconf);
void init(const std::string& logconf, std::string process_name);
void update_process_name(std::string process_name);
std::string trace();


// clang-format off
#define LOG_verbose                                                                                                  \
    BOOST_LOG_SEV(::global_logger::get(), ::Everest::Logging::verbose)                                                 \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("file", __FILE__)                                        \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("line", __LINE__)                                        \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("function", BOOST_CURRENT_FUNCTION)

#define LOG_debug                                                                                                    \
    BOOST_LOG_SEV(::global_logger::get(), debug)                                                   \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("function", BOOST_CURRENT_FUNCTION)

#define LOG_info                                                                                                     \
    BOOST_LOG_SEV(::global_logger::get(), info)

#define LOG_warning                                                                                                  \
    BOOST_LOG_SEV(::global_logger::get(), warning)                                                 \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("function", BOOST_CURRENT_FUNCTION)

#define LOG_error                                                                                                    \
    BOOST_LOG_SEV(::global_logger::get(), error)                                                   \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("function", BOOST_CURRENT_FUNCTION)

#define LOG_critical                                                                                                 \
    BOOST_LOG_SEV(::global_logger::get(), critical)                                                \
        << boost::log::BOOST_LOG_VERSION_NAMESPACE::add_value("function", BOOST_CURRENT_FUNCTION)
// clang-format on

#define LOG_AND_THROW(ex)                                                                                            \
    do {                                                                                                               \
        try {                                                                                                          \
            BOOST_THROW_EXCEPTION(boost::enable_error_info(ex)                                                         \
                                  << boost::log::BOOST_LOG_VERSION_NAMESPACE::current_scope());                        \
        } catch (std::exception & e) {                                                                                 \
            EVLOG_error << e.what();                                                                                   \
            throw;                                                                                                     \
        }                                                                                                              \
    } while (0)

#define THROW(ex)                                                                                                    \
    do {                                                                                                               \
        BOOST_THROW_EXCEPTION(boost::enable_error_info(ex)                                                             \
                              << boost::log::BOOST_LOG_VERSION_NAMESPACE::current_scope());                            \
    } while (0)

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(
    global_logger,
    boost::log::BOOST_LOG_VERSION_NAMESPACE::sources::severity_logger_mt<severity_level>)

#endif // LOGGING_HPP
