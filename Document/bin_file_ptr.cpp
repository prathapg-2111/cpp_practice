#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
struct Record
{
    int id;
    char name[10];
};

void WriteRecord(Record *p)
{
    std::ofstream binStream("records", std::ios::binary | std::ios::out);
    binStream.write((const char *)p, sizeof(Record));
}

Record GetRecord()
{
    std::ifstream input("records", std::ios::binary | std::ios::in);
    Record r;
    input.read((char *)&r, sizeof(Record));
    return r;
}

int main()
{
    Record r;
    r.id = 10001;
    strcpy_s(r.name, 10, "Prathap");
    WriteRecord(&r);

    Record r2;
    std::cout << r2.id << ":" << r2.name;
    std::ofstream textstream{"data.txt"};
    textstream << 12345678;

    std::ofstream binStream{"binary", std::ios::binary | std::ios::out};
    int num{12345678};
    binStream.write((const char *)&num, sizeof(num));
    binStream.close();
    std::ifstream input("binary", std::ios::binary | std::ios::in);
    input.read((char *)&num, sizeof(num));
    std::cout << num << std::endl;
    return 0;
}