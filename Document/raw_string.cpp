#include <iostream>
#include <string>

int main()
{
    std::string filename{R"(C:\temp\newfile.txt)"};
    std::cout << filename << std::endl;
    std::string message{R"(C++ introduced filesystem API"(In C++ 17) ")"};
    std::cout << message << std::endl;
    return 0;
}