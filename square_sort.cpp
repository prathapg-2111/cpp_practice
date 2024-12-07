#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // For exceptions

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            throw std::runtime_error("Input vector is empty");
        }

        for (int &num : nums)
        {
            num = num * num;
        }

        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    Solution solution;

    // Input vector for testing
    std::vector<int> nums = {-4, -1, 0, 3, 10};

    try
    {
        std::vector<int> result = solution.sortedSquares(nums);

        std::cout << "Sorted Squares: ";
        for (int num : result)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
