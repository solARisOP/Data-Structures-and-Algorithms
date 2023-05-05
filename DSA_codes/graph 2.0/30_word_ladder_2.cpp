#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    // code here
    unordered_set<string> s(wordList.begin(), wordList.end());
    s.erase(beginWord);

    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> del;
    del.push_back(beginWord);
    
    int level = 0;

    vector<vector<string>> ans;
    while (!q.empty())
    {
        vector<string> words = q.front();
        q.pop();

        if (words.size() > level)
        {
            level++;
            for (auto it : del)
            {
                s.erase(it);
            }
        }

        string word = words.back();
        if (word == endWord)
        {
            if (!ans.size())
                ans.push_back(words);
            else if (words.size() == ans[0].size())
                ans.push_back(words);
            continue;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    words.push_back(word);

                    del.push_back(word);
                    q.push(words);
                    
                    words.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;
}

int main()
{

    return 0;
}