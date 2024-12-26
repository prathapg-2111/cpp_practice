#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> runningSum(vector<int> nums)
    {
        vector<int> result = {nums[0]};
        for(int i =1;i<nums.size();i++)
        {
            result.push_back(result.back()+nums[i]);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3,4,1,2,10,1};
    Solution solution;
    vector<int> result = solution.runningSum(nums);

    for(int i = 0;i<nums.size();i++)
        cout << nums[i] << ",";
   
    cout << "\n";

    for(int i = 0;i<nums.size();i++)
        cout << result[i] << ",";
}