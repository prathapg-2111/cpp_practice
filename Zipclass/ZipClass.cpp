#include <iostream>
class Zip final
{
public:
    Zip() {}
    void Compress(const std::string &filename) {};
    void Decompress(const std::string &filename) {};
    void PrintStatistics() {};
    ~Zip() {};
};

class Document
{
public:
    virtual void Serialize(float version)
    {
        std::cout << "Document: serialize" << std::endl;
    }
};

class Text : public Document
{
public:
    void Serialize(float version) override
    {
        std::cout << "Text: serialize" << std::endl;
    }
};

class RichText : public Text
{
public:
    void Serialize(float version) override
    {
        std::cout << "RichText: serialize" << std::endl;
    }
};

int main()
{
    Text t;
    Document &doc = t;
    doc.Serialize(1.2f);
    return 0;
}