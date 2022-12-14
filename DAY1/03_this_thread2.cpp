#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;


time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
    std::time_t tt = _mkgmtime(&timeinfo);
#else
    time_t tt = timegm(&timeinfo);
#endif
    return tt;
}

std::chrono::system_clock::time_point createDateTime(int year, int month, int day, int hour, int minute, int second)
{
    tm timeinfo1 = tm();
    timeinfo1.tm_year = year - 1900;
    timeinfo1.tm_mon = month - 1;
    timeinfo1.tm_mday = day;
    timeinfo1.tm_hour = hour;
    timeinfo1.tm_min = minute;
    timeinfo1.tm_sec = second;
    tm timeinfo = timeinfo1;
    time_t tt = toUTC(timeinfo);
    return std::chrono::system_clock::from_time_t(tt);
}

int main()
{
    // 2. sleep_for : 특정 시간 동안 현재 스레드 재우기
//  std::this_thread::sleep_for(3); // error
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    std::this_thread::sleep_for(3s);


    // 3. sleep_until : 특정 시간 "까지" 재우기
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 200ms);

    // 특정 날짜 까지 재우기
    auto t1 = createDateTime(2022, 11, 28, 11, 50, 0);

    std::this_thread::sleep_until(t1);

    // 4. yield : 현재 스레드 실행을 포기하고 다른 스레드를 실행하라는 명령
    std::this_thread::yield();
}



