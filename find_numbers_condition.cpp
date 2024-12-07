/*
Given an integer array nums,
find all the unique numbers x in num
x+1 is not in nums
x-1 in not in nums
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> findNumbers(vector<int> &nums)
    {
        vector<int> ans;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : numSet)
        {
            if (numSet.find(num + 1) == numSet.end() &&
                numSet.find(num - 1) == numSet.end())
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> numSet = {4, 7, 8, 6, 2, 5, 9};
    // int len = numSet.size();
    vector<int> ans = solution.findNumbers(numSet);
    int len = ans.size();
    for (int i = 0; i < len; i++)
    {
        std::cout << ans[i];
    }
}