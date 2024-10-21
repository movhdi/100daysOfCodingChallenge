#include <databasehandler.hpp>

// namespace logging = boost::log;
// namespace sinks = boost::log::sinks;
// namespace src = boost::log::sources;
// namespace expr = boost::log::expressions;
// namespace attrs = boost::log::attributes;
// namespace keywords = boost::log::keywords;
// void init()
// {
//     logging::add_file_log
//     (
//         keywords::file_name = "sample_%N.log",                                        /*< file name pattern >*/
//         keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
//         keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
//         keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
//     );

//     logging::core::get()->set_filter
//     (
//         logging::trivial::severity >= logging::trivial::info
//     );
// }

DatabaseHandler::DatabaseHandler(std::string fileName) : pth(fileName)
{
}

int DatabaseHandler::database_open() {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc)
    {
        std::cout << sqlite3_errmsg(db);
        return rc;
    }
    // init();
    // logging::add_common_attributes();

    // using namespace logging::trivial;
    // src::severity_logger< severity_level > lg;

    // BOOST_LOG_SEV(lg, info) << "An informational severity message";
    return 0;
}

DatabaseHandler::~DatabaseHandler()
{
    sqlite3_close(this->db);
}
