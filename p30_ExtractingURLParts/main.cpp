#include <iostream>
#include <regex>
#include <sstream>
#include <mutex>
#include <iterator>
#include <string_view>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <string>


struct uri_parts
{
    std::string domain;
    std::string protocol;
    std::optional<int> port;
    std::optional<std::string> fragment;
    std::optional<std::string> path;
    std::optional<std::string> query;
};

std::optional<uri_parts> parse_uri(std::string uri_text)
{
  // The following lines of comments are the number of submatches.
  // These numbers when used for indexing in std::smatch start from 0

  //                  (                              1st  (0index)                          )
  //                  (2st)     (      3nd      )(  4rd  )(    6th  ) (          7th        )
  //                  |   |     |               || (5th) ||         | |  ( 8th   )(    9th  )
  //                  |   |     |               || |   | ||         | |  |       |   (10th) |
    std::regex rx(R"(^(\w+):\/\/([a-zA-Z0-9\._]+)(:(\d+)?)([\w\.\/]+)?(\?([\w=&]*)(#(\w+))?)?$)");
    std::smatch sm;

    if (std::regex_match(uri_text, sm, rx))
    {
        if (sm[1].matched && sm[2].matched)
        {
            uri_parts result;
            result.domain = sm[2].str();
            std::cout << "Domain : " << sm[2].str() << std::endl;
            result.protocol = sm[1].str();
            std::cout << "Protocol : " << sm[1].str() << std::endl;
            if (sm[3].matched)
            {
                result.port = std::stoi(sm[4].str());
                std::cout << "Port : " << sm[4].str() << std::endl;
            }
            if (sm[5].matched)
            {
                result.path = sm[5].str();
                std::cout << "Path : " << sm[5].str() << std::endl;
            }
            if (sm[7].matched)
            {
                result.query = sm[7].str();
                std::cout << "Query : " << sm[7].str() << std::endl;
            }
            if (sm[9].matched)
            {
                result.fragment = sm[9].str();
                std::cout << "Fragment : " << sm[9].str() << std::endl;
            }
            return result;
        }
    }
    return {};
}

int main()
{
    auto p1 = parse_uri("https://www.google.com:8080/ul/client.aspx?little=fuse#ui"); //selfmade URI
    assert(p1->domain == "www.google.com");
    assert(p1->protocol == "https");
    assert(p1->port == 8080);
    assert(p1->path == "/ul/client.aspx");
    assert(p1->fragment == "ui");
    assert(p1->query == "little=fuse");
    return 0;
}
