#include <iostream>

void checkEndianness()
{
    unsigned int num = 1;
    char *bytePtr = reinterpret_cast<char *>(&num);

    if (*bytePtr == 1)
    {
        std::cout << "The machine is Little-Endian." << std::endl;
    }
    else
    {
        std::cout << "The machine is Big-Endian." << std::endl;
    }
}

int main()
{
    checkEndianness();
    return 0;
}
