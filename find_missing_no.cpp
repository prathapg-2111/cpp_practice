#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_set<int> miss;
        for (int i : nums)
        {
            if (miss.find(i) != miss.end())
            {
                return i;
            }
            miss.insert(i);
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int val = solution.missingNumber(nums);
    cout << val << endl;
}