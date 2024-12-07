#include <iostream>
#include <fstream>
#include <string>

void Write()
{
    std::ofstream out("data.txt");
    out << "Hello World" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Write_new()
{
    std::ofstream out("test.txt");
    if (!out)
    {
        std::cout << "could not open the file for writing" << std::endl;
        return;
    }
    std::string message("C++ was invented by Bjarne stroustrup");
    for (char ch : message)
    {
        out.put(ch);
    }
    out.seekp(5);
    out.put('#');
}

void Read_new()
{
    std::ifstream in("test.txt");
    if (!in)
    {
        std::cout << "Source file not found" << std::endl;
        return;
    }
    // in.seekg(10, std::ios::beg);
    std::cout << "current position is" << in.tellg() << std::endl;
    char ch{};
    while (in.get(ch))
    {
        std::cout << ch;
    }
}

void Read()
{
    std::ifstream input{"input.txt"};
    input.open("data.txt");
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    input.close();
    std::cout << message << value << std::endl;
}

UsingFStream()
{
    std::fstream stream{"file.txt"};
    if (!stream)
    {
        std::cout << "FILE DOESNT EXIST. CREAING ONE" << std::endl;
        std::ofstream out{"file.txt"};
        out.close();
        stream.open("file.txt");
    }
    stream << "Hello World" << std::endl;
    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}
int main()
{
    // Write_new();
    // Read_new();
    UsingFStream();
    return 0;
}