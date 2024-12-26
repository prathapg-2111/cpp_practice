#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
class Solution{
	public:
	int maxVowels(string s, int k)
	{
		unordered_set<char> vowels = {'a','e','i','o','u'};
		int count = 0;
		int maxCount = 0;

		for(int i =0;i<k && i<s.length();i++)
		{
			if(vowels.count(s[i])){
				count++;
			}
		}
		maxCount = count;

		for(int i=k;i<s.length();i++)
		{
			if(vowels.count(s[i-k])){
				count--;
			}

			if(vowels.count(s[i])){
				count++;
			}
			maxCount = max(maxCount, count);
		}
		return maxCount;

	}
	
};

int main()
{
	Solution solution;
	string s = "abciiidef";
	int count = solution.maxVowels(s,3);
	cout << "Max vowels in k size string " << count;
	return 0;
}

