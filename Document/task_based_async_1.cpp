#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <future>

void Download()
{
    using namespace std::chrono_literals;
    for (int i = 0; i < 10; i++)
    {
        std::cout << '.';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::future<void> result = std::async(Download);
    // Download();
    std::cout << "Main thread continues its execution\n"
              << std::endl;
    result.get();
    return 0;
}