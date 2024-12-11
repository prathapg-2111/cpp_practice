#include <iostream>
#include <list>
#include <thread>

std::list<int> g_Data;
const int SIZE = 10000000;

class String
{
public:
    String()
    {
        std::cout << "String()" << std::endl;
    }
    String(const String &)
    {
        std::cout << "String(const string &)" << std::endl;
    }
    String &operator=(const String &)
    {
        std::cout << "Operator=(const String&)" << std::endl;
        return *this;
    }
    ~String()
    {
        std::cout << "~String()" << std::endl;
    }
};
void Download(const String &file)
{
    // std::cout << "[Downloader]Started download of file" << file << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        g_Data.push_back(i);
    }
    std::cout << "[Downloader]Finished download" << std::endl;
}

int main()
{
    String file;
    std::cout << "User Starting the operation" << std::endl;
    std::thread thDownloader(Download, std::cref(file));
    // thDownloader.detach();
    std::cout << "User Started the operation" << std::endl;
    if (thDownloader.joinable())
        thDownloader.join();
    system("Pause");
    return 0;
}