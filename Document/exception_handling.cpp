// Mechanism to handle errors runtime
//  these errors are called exceptions
// exist outside the normal functioning of the prgram
//  require immediate handling of the program
//  if not handled, the program crashes,
// cannot be ignored, unlike C error handling
#include <iostream>
#include <limits>
#include <vector>
#include <memory>
#include <random>
class Test
{
public:
    Test()
    {
        std::cout << "Test(): Acquire resources" << std::endl;
    }
    ~Test()
    {
        std::cout << "Test:Release resources" << std::endl;
    }
};
// Resource acquisition is initialization
int ProcessRecords(int count)
{
    std::unique_ptr<Test> t(new Test);
    std::cout << count << std::endl;
    // int *p = new int[count];
    std::vector<int> p;
    p.reserve(count);
    std::vector<int> pArray;
    pArray.reserve(count);
    for (int i = 0; i < count; i++)
    {
        pArray.push_back(i);
    }
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int error{};
    for (int i = 0; i < count; ++i)
    {
        try
        {
            std::cout << "Processing record #:" << i << "";
            if (!dist(eng))
            {
                throw ::std::runtime_error("could not process the record");
            }
        }
        catch (std::runtime_error &ex)
        {
            std::cout << "Error" << ex.what() << std::endl;
            if (error > 8)
                std::runtime_error err("Too many errors. Abandoning operation");
            ex = err;
            throw;
        }
    }
    // int *pArray = (int *)malloc(count * sizeof(int));
    // if (pArray == nullptr)
    //{
    //  throw std::runtime_error("Failed to allocate memory");
    //}
    // for (int i = 0; i < count; i++)
    // {
    //   pArray[i] = i;
    //}
    // free(pArray);
    // delete[] p;
    return 0;
}

int main()
{
    try
    {
        ProcessRecords(std::numeric_limits<int>::max());
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::out_of_range &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "prathap" << std::endl;
    return 0;
}