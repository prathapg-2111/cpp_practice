#include <iostream>
using namespace std;

class Polymorphism
{
public:
    virtual int printValue()
    {
        cout << "Base class" << endl;
        return 0; // Return a valid int
    }
    virtual ~Polymorphism() {} // Virtual destructor for safety
};

class ChildPoly : public Polymorphism
{
public:
    int printValue() override
    {
        cout << "Derived class" << endl;
        return 1; // Return a valid int
    }
};

int main()
{
    ChildPoly childInstance;                            // Create a ChildPoly instance
    Polymorphism *poly = &childInstance;                // Base pointer to derived object
    ChildPoly *child = dynamic_cast<ChildPoly *>(poly); // Downcasting

    if (child)
    {
        child->printValue(); // Calls ChildPoly::printValue()
    }
    else
    {
        cout << "Downcasting failed!" << endl;
    }

    return 0;
}
