/*check if given sentence is a pangram*
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findPlayersWithLoses(vector<vector<int>> &matches)
    {
        unordered_map<int, int> loosersCount;
        for (auto &match : matches)
        {
            int winner = match[0], looser = match[1];
            if (loosersCount.find(winner) == loosersCount.end())
            {
                loosersCount[winner] = 0;
            }
            loosersCount[looser]++;
        }
        vector<vector<int>> answer(2, vector<int>());
        for (auto [player, count] : loosersCount)
        {
            if (count == 0)
            {
                answer[0].push_back(player);
            }
            else if (count == 1)
            {
                answer[1].push_back(player);
            }
        }
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    Solution solution;
    vector<vector<int>> val = solution.findPlayersWithLoses(matches);
    for (auto &value : val)
        std::cout << value[0] << " " << value[1];
}