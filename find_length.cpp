#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums, int k)
    {
        int curr = 0;
        int answer = 0;
        int len = nums.size();
        int left = 0;

        for (int right = 0; right < len; right++)
        {
            curr += nums[right];
            while (curr > k)
            {
                curr -= nums[left];
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {3, 1, 2, 7, 4, 2, 1, 1, 5};
    int k = 8;
    Solution solution;
    int length = solution.findLength(nums, k);
    cout << length;
}
