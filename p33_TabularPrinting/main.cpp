#include <streambuf>
#include <sstream>
#include <iostream>
#include <mutex>
#include <string_view>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
#include <linux/kernel.h>
#include <sched.h>
#include <linux/module.h>
#include <sys/ptrace.h>
#include <iomanip>

enum class procStatus
{
    suspended,
    running
};

enum class platforms
{
    p32bit,
    p64bit
};

struct procsinfo
{
    std::string name;
    size_t identifier;
    procStatus status;
    std::string accountName;
    size_t memory_size;
    platforms platform;
};

std::string status_to_string(procStatus status)
{
    if (status == procStatus::running)
    {
        return "running";
    }else
    {
        return "suspended";
    }
}

std::string platform_to_string(platforms platform)
{
    if (platform == platforms::p32bit)
    {
        return "p32bit";
    }else
    {
        return "p64bit";
    }
}


void print_processes(std::vector<procsinfo> procs)
{
    std::sort(procs.begin(),procs.end(), [](procsinfo p1, procsinfo p2){return p1.name < p2.name;});
    for (auto it : procs)
    {
        std::cout << std::setfill(' ') << std::setw(15) << std::left << it.name;
        std::cout << std::setfill(' ') << std::setw(10) << std::left << it.identifier;
        std::cout << std::setfill(' ') << std::setw(10) << std::left << status_to_string(it.status);
        std::cout << std::setfill(' ') << std::setw(15) << std::left << it.accountName;
        std::cout << std::setfill(' ') << std::setw(10) << std::right << it.memory_size;
        std::cout << "  " << std::left << platform_to_string(it.platform);
        std::cout << std::endl;
    }
}

int main()
{
    using namespace std::string_literals;
    std::vector<procsinfo> processes{
        {"cmd.exe"s, 512, procStatus::running, "SYSTEM"s, 48, platforms::p64bit},
        {"chrome.exe"s, 1044, procStatus::running, "marius.bancila"s, 25180, platforms::p32bit},
        {"chrome.exe"s, 10100, procStatus::running, "marius.bancila"s, 227756, platforms::p32bit},
        {"explorer.exe"s, 7108, procStatus::running, "marius.bancila"s, 29529, platforms::p64bit},
        {"skype.exe"s, 22456, procStatus::suspended, "marius.bancila"s, 656, platforms::p64bit}};

    print_processes(processes);
    return 0;
}
