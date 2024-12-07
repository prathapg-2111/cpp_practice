#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Function to remove consecutive duplicate letters from a string
string removeConsecutiveDuplicates(const string &str)
{
    string result;
    for (char ch : str)
    {
        if (result.empty() || result.back() != ch)
        {
            result.push_back(ch);
        }
    }
    return result;
}

// Function to solve the problem
void solve(const string &inputString)
{
    // Split the input string into words
    vector<string> inputWords;
    stringstream ss(inputString);
    string word;
    while (ss >> word)
    {
        inputWords.push_back(word);
    }

    // Process each word to remove consecutive duplicates
    vector<string> resultWords;
    for (const string &word : inputWords)
    {
        resultWords.push_back(removeConsecutiveDuplicates(word));
    }

    // Print the modified words as a space-separated string
    for (int i = 0; i < resultWords.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << resultWords[i];
    }
    cout << endl;
}

int main()
{
    string inputString = "aabbcc ddeeffggg hhhhiiiijjjjkk llmnnnooo";
    solve(inputString);
    return 0;
}
