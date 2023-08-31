#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node
{
    Node* links[26];
    int cnt_words=0;
    int cnt_prefix=0;

    public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node * node)
    {
        links[ch - 'a'] = node;
    }

    void setPrefix()
    {
        cnt_prefix++;
    }

    Node * get(char ch)
    {
        return links[ch-'a'];
    } 

    void setEnd()
    {
        cnt_words++;
    }

    int countWords()
    {
        return cnt_words;
    }

    int countPrefix()
    {
        return cnt_prefix;
    }

    void removePrefix()
    {
        cnt_prefix--;
    }

    void removeWord()
    {
        cnt_words--;
    }

    
};

class Trie{
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            char ch = word[i];
            if(!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }

            node = node->get(ch);
            node->setPrefix();
        }

        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            char ch = word[i];
            if(!node->containsKey(ch))return 0;

            node = node->get(ch);
        }
        
        return node->countWords();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            char ch = word[i];
            if(!node->containsKey(ch))return 0;

            node = node->get(ch);
        }
        
        return node->countPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            char ch = word[i];
            node = node->get(ch);
            node->removePrefix();
        }
        
        node->removeWord();
    }
};


int main()
{
    
    return 0;
}