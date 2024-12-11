#include <iostream>
#include <thread>
#include <Windows.h>
void Process()
{
    std::cout << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::microseconds());
        std::cout << i << ' ';
    }
}

int main()
{
    std::thread t1(Process);
    auto id = t1.get_id();
    // t1.pthread_setname("myThread");
    //  std::cout << id << std::endl;
    // HANDLE handle = t1.native_handle();
    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores  " << cores << std::endl;
    t1.join();
    return 0;
}