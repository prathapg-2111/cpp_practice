/*Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int largetUnique(vector<int> &nums)
    {
        unordered_map<int, int> fmap;

        for (int num : nums)
        {
            fmap[num]++;
        }
        int largestUnique = -1;
        for (auto pair : fmap)
        {
            if (pair.second == 1 && pair.first > largestUnique)
            {
                largestUnique = pair.first;
            }
        }

        return largestUnique;
    }
};

int main()
{
    vector<int> nums = {5, 7, 7, 3, 9, 4, 9, 8, 8, 3, 1};
    Solution solution;
    int val = solution.largetUnique(nums);
    cout << val;
}