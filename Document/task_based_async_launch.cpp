#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <future>

int Download(int count)
{
    using namespace std::chrono_literals;
    int sum{};
    for (int i = 0; i < count; i++)
    {
        sum += i;
        std::cout << '.';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return sum;
}

int main()
{
    using namespace std::chrono_literals;
    std::future<int> result = std::async(std::launch::deferred, Download, 10);
    std::this_thread::sleep_for(1s);
    std::cout << "Main thread continues its execution\n"
              << std::endl;
    if (result.valid())
    {
        auto sum = result.get();
        std::cout << "Sum  " << sum << std::endl;
    }
    return 0;
}