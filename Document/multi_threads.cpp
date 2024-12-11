#include <iostream>
#include <list>
#include <thread>
#include <mutex>

std::list<int> g_Data;

const int SIZE = 10000;
std::mutex g_Mutex;
void Download()
{
    for (int i = 0; i < SIZE; i++)
    {
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }
}
void Download2()
{
    for (int i = 0; i < SIZE; i++)
    {
        g_Mutex.lock();
        g_Data.push_back(i);
        if (i == 500)
        {
            return;
        }
        g_Mutex.unlock();
    }
}

int main()
{
    std::thread thDownloader(Download);
    std::thread thDownloader2(Download2);
    thDownloader.join();
    thDownloader2.join();
    std::cout << g_Data.size() << std::endl;
    return 0;
}