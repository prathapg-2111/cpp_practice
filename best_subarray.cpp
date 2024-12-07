#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findBestSubArray(vector<int> &nums, int k)
    {
        int curr = 0;
        int answer = 0;
        int len = nums.size();
        int left = 0;

        for (int right = 0; right < k; right++)
        {
            curr += nums[right];
        }
        answer = curr;
        for (left = k; left < len; left++)
        {
            curr += nums[left] - nums[left - k];
        }
        answer = max(answer, curr);
        return answer;
    }
};

int main()
{
    vector<int> nums = {3, -1, 4, 12, -8, 5, 6};
    int k = 4;
    Solution solution;
    int length = solution.findBestSubArray(nums, k);
    cout << length;
}
