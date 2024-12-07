#include <iostream>
class Document
{
public:
    // virtual void Serialize(float version)
    //{
    //   std::cout << "Document:: Serialize" << std::endl;
    //}
    virtual void Serialize(float version) = 0;
};

class Text : public Document
{
public:
    void Serialize(float version) override final
    {
        std::cout << "Text: Serialize" << std::endl;
    }
};

// An abstract has atleast one pure virtual function
//  can contain other members (data, non virtual functions, etc)
//  cannot be instantiated, but used through the pointer or reference
// Establishes a contract with clients
// Abstract classes are used to create Interfaces
// Pure virtual function marked with 0
// Does not have implementation (optional)
// if the implementation of the pure virtual function is provided,
// they can be invoked only by the derived classes
// An implemenation in a pure virtual function may be provided by author
// to provide default behavior for the child classes.
// Dont have an entry in the vtable.
// it has entry in the child classes.
// Must be over ridden in the derived class, if not overridden the derived classes
// also become pure virtual, and cannot be instantiated.

class RichText : public Text
{
public:
    // Cannnot override because the function is final in base
    // void Serialize(float version) override final
    //{
    //  std::cout << "Text: Serialize" << std::endl;
    //}
};

class XML : public Document
{
public:
    void Serialize(float version) override final
    {
        std::cout << "XML: Serialize" << std::endl;
    }
};

void Write(Document *p)
{
    p->Serialize(1.1f);
}

int main()
{
    XML xml;
    Write(&xml);
    return 0;
}
