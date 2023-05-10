#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<int, string>> q;
    q.push({1, beginWord});

    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    int size = beginWord.length();
    while (!q.empty())
    {
        int steps = q.front().first;
        string word = q.front().second;

        q.pop();
        if (word == endWord)
            return steps;
        for (int i = 0; i < size; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({steps + 1, word});
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