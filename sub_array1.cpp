#include <iostream>
#include <vector>
#include <unordered_map>

bool isSubArray(const std::vector<int> &A, const std::vector<int> &B)
{
    int n = A.size();
    int m = B.size();

    if (m > n)
        return false;

    // Helper function to count element frequencies in a vector
    auto countFrequency = [](const std::vector<int> &arr, int start, int end)
    {
        std::unordered_map<int, int> freq;
        for (int i = start; i <= end; ++i)
        {
            freq[arr[i]]++;
        }
        return freq;
    };

    // Count the frequency of elements in B
    std::unordered_map<int, int> B_freq;
    for (int b : B)
    {
        B_freq[b]++;
    }

    // Sliding window over A
    for (int i = 0; i <= n - m; ++i)
    {
        // Count frequency of current window in A
        std::unordered_map<int, int> window_freq = countFrequency(A, i, i + m - 1);

        // Compare frequencies
        if (window_freq == B_freq)
        {
            return true;
        }
    }

    return false;
}

// Test cases
int main()
{
    std::vector<int> A1 = {3, 2, 7, 1, 4, 6};
    std::vector<int> B1 = {7, 1, 4};
    std::cout << (isSubArray(A1, B1) ? "True" : "False") << std::endl; // True

    std::vector<int> A2 = {3, 2, 7, 1, 4, 6};
    std::vector<int> B2 = {4, 7, 1};
    std::cout << (isSubArray(A2, B2) ? "True" : "False") << std::endl; // True

    std::vector<int> A3 = {3, 2, 7, 1, 4, 6};
    std::vector<int> B3 = {3, 1, 4};
    std::cout << (isSubArray(A3, B3) ? "True" : "False") << std::endl; // False

    std::vector<int> A4 = {3, 2, 7, 7, 4, 6};
    std::vector<int> B4 = {7, 4, 4};
    std::cout << (isSubArray(A4, B4) ? "True" : "False") << std::endl; // False

    std::vector<int> A5 = {2, 2, 2, 2, 2, 7};
    std::vector<int> B5 = {2, 2, 2, 2, 7};
    std::cout << (isSubArray(A5, B5) ? "True" : "False") << std::endl; // True

    return 0;
}
