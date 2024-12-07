#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Compare two vectors to see if their frequency of elements matches
bool compareFrequency(const vector<int> &arrB, const vector<int> &arrC)
{
    unordered_map<int, int> freqB, freqC;

    for (int b : arrB)
        freqB[b]++;
    for (int c : arrC)
        freqC[c]++;

    return freqB == freqC;
}

bool isBSubArrayOfA(const vector<int> &arrA, int m, const vector<int> &arrB, int n)
{
    if (n > m)
        return false; // If B is longer than A, it's not possible

    // Sliding window over arrA
    for (int i = 0; i <= m - n; ++i)
    {
        vector<int> arrC(arrA.begin() + i, arrA.begin() + i + n); // Extract subarray
        if (compareFrequency(arrB, arrC))
        {
            return true; // Found a matching subarray
        }
    }
    return false; // No match found
}

int main()
{
    vector<int> a = {3, 2, 7, 1, 4, 6};
    vector<int> b = {7, 1, 4};
    // vector<int> a = {2, 2, 2, 2, 2, 7};
    // vector<int> b = {2, 2, 2, 2, 7};

    int m = a.size();
    int n = b.size();
    bool sub = isBSubArrayOfA(a, m, b, n);
    cout << (sub ? "True" : "False") << endl;
    return 0;
}
