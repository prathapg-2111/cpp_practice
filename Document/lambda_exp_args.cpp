#include <iostream>
// using Comparator = bool (*)(int, int);
template <typename T, int size, typename Comparator>
void Sort(T (&arr)[size], Comparator comp)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (comp(arr[j], arr[j + 1]))
            {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(temp);
            }
        }
    }
}

struct Comp2
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};

bool Comp(int x, int y)
{
    return x > y;
}
bool Comp1(int x, int y)
{
    return x < y;
}
template <typename T, int size, typename Callback>
void ForEach(T (&arr)[size], Callback operation)
{
    for (int i = 0; i < size - 1; ++i)
    {
        operation(arr[i]);
    }
}
int main()
{
    // Comp2 comp;
    // comp(3, 5);
    int arr[] = {1, 6, 8, 4, 0};
    ForEach(arr, [](auto x)
            { std::cout << x << " "; });
    int offset = 5;
    ForEach(arr, [offset](auto &x) mutable
            { x += offset; 
            ++offset; });
    std::cout << std::endl;
    ForEach(arr, [](auto x)
            { std::cout << x << " "; });

    return 0;
}

void OldCode()
{
    int arr[] = {1, 6, 8, 4, 0};
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    auto comp = [](auto x, auto y)
    {
        return x > y;
    };
    Sort(arr, comp);
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}