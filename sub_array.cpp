#include <iostream>
#include <vector>
using namespace std;

bool compareKWindow(vector<int> arrB, vector<int> arrC)
{
    int size = arrC.size();

    for (int i = 0; i < size; i++)
    {
        int countB = 0, countC = 0;
        for (int j = 0; j < size; j++)
        {
            if (arrB[i] == arrB[j])
                countB++;
            if (arrB[i] == arrC[j])
                countC++;
        }
        if (countB != countC)
            return false;
    }

    return true;
}

bool isBSubArrayOfA(vector<int> arrA, int m, vector<int> arrB, int n)
{
    if (n > m)
        return false;

    int i = 0;
    while (i <= m - n)
    {
        vector<int> arrC(n);
        int k = 0;
        int count = i;
        int j = 0;
        while (j < n)
        {
            arrC[k++] = arrA[count++];
            j++;
        }

        if (compareKWindow(arrB, arrC))
        {
            return true;
        }
        i++;
    }

    return false;
}

int main()
{
    // vector<int> a = {3, 2, 7, 1, 4, 6};
    // vector<int> b = {7, 1, 4};
    vector<int> a = {2, 2, 2, 2, 2, 7};
    vector<int> b = {2, 2, 2, 2, 7};
    int m = a.size();
    int n = b.size();
    bool sub = isBSubArrayOfA(a, m, b, n);
    cout << sub;
}