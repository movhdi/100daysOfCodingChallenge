
#include "date/tz.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>

#define INSTALL ../../include/date/

struct participant
{
    std::string city;
    std::string name;
public:
    participant(std::string c, std::string n) : city(c), name(n)
    {
    }
};

template <typename prtcpnt, typename meetingtime>
void display_meeting_time(prtcpnt participant, meetingtime time)
{

}

using namespace std::chrono_literals;
using namespace date;

int main()
{
    std::vector<participant> participants;
    participants.push_back(participant("America/New_York", "Mahdi Movahedi"));
    auto meeting = make_zoned("Asia/Tehran", local_days{December/30/1978} );

    // display_meeting_time(participants, );
}
