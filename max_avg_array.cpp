#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double maxAvgArray(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (len < k)
        {
            throw runtime_error("Array size must be at least k.");
        }

        // Calculate the sum of the first `k` elements
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        // Initialize the maximum average with the average of the first subarray
        double maxAvg = static_cast<double>(sum) / k;

        // Slide the window through the array
        for (int i = k; i < len; i++)
        {
            sum = sum - nums[i - k] + nums[i]; // Slide the window
            maxAvg = max(maxAvg, static_cast<double>(sum) / k);
        }

        return maxAvg;
    }
};

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    Solution solution;
    int k = 4;
    double val = solution.maxAvgArray(nums, k);
    cout << val << endl;
}