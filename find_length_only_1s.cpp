#include <iostream>
#include <string>
class Solution
{
public:
    int findLength(const std::string &s)
    {
        int left = 0;
        int curr = 0;
        int ans = 0;
        int len = s.size();
        for (int right = 0; right < len; right++)
        {
            if (s[right] == '0')
            {
                curr++;
            }
            while (curr > 1)
            {
                if (s[left] == '0')
                {
                    curr--;
                }
                left++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    using namespace std;
    std::string s = "11001011";
    Solution solution;
    int ans = solution.findLength(s);
    std::cout << ans;
}