#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(string &word, string &beginWord, vector<string> &seq, vector<vector<string>> &ans, unordered_map<string, int> &mpp)
{
    if (word == beginWord)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());

        return;
    }

    int steps = mpp[word];
    int size = word.size();
    for (int i = 0; i < size; i++)
    {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(word, beginWord, seq, ans, mpp);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_map<string, int> mpp;
    unordered_set<string> s(wordList.begin(), wordList.end());

    queue<string> q;
    q.push(beginWord);

    mpp[beginWord] = 1;

    s.erase(beginWord);
    int size = beginWord.size();
    while (!q.empty())
    {
        string word = q.front();
        int steps = mpp[word];
        q.pop();

        if (word == endWord)
            break;
        for (int i = 0; i < size; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.count(word))
                {
                    s.erase(word);
                    q.push(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> ans;
    vector<string> seq;
    if (mpp.find(endWord) != mpp.end())
    {
        seq.push_back(endWord);
        dfs(endWord, beginWord, seq, ans, mpp);
    }

    return ans;
}

int main()
{

    return 0;
}