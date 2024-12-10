#include <iostream>

class Stack
{
    int m_Buffer[512];
    int m_Top{-1};

public:
    void Push(int elem)
    {
        m_Buffer[++m_Top] = elem;
    }
    void Pop()
    {
        --m_Top;
    }
    int Top() const
    {
        return m_Buffer[m_Top];
    }
    bool IsEmpty()
    {
        return m_Top == -1;
    }
};

int main()
{
    Stack s;
    s.Push(3);
    s.Push(3);
    s.Push(3);
    s.Push(3);

    while (!s.IsEmpty())
    {
        std::cout << s.Top() << " ";
        s.Pop();
    }
    return 0;
}