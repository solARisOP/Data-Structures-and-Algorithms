#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // Code here
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;

    s.erase(startWord);
    q.push({startWord, 1});

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;

        q.pop();
        if (word == targetWord)
            return steps;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

int main()
{

    return 0;
}