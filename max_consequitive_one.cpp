#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxConsequitiveOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int curr = 0;
        int ans = 0;
        int len = nums.size();
        for (int right = 0; right < len; right++)
        {
            if (nums[right] == 0)
                curr++;
            while (curr > k)
            {
                if (nums[left] == 0)
                    curr--;
                left++;
            }
            ans = std::max(ans, (right - left + 1));
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int val = solution.maxConsequitiveOnes(nums, k);
    cout << val;
}