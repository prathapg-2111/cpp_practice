/*check if given sentence is a pangram*
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool isPangram(string s)
    {
        // std::string s;
        unordered_set<char> charSet;
        for (char c : s)
        {
            if (charSet.find(c) == charSet.end())
                charSet.insert(c);
        }
        cout << charSet.size();
        if (charSet.size() == 26)
            return true;
        return false;
    }
};

int main()
{
    Solution solution;
    string s = "thequickbrownfoxjumpsoverthelazydog";
    bool val = solution.isPangram(s);
    cout << val << endl;
}