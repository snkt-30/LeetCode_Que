#include "bits/stdc++.h"
using namespace std;


//26ms
bool isAnagram(string s, string t)
{
    unordered_map<char, int> fr;

    if (s.length() != t.length())
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        fr[s[i]]++;
        fr[t[i]]--;
    }

    for (auto x : fr)
    {
        if (x.second)
        {
            return false;
        }
    }
    return true;
}

// 3ms
bool isAnagramop(string s, string t)
{
    if (s == t)
        return true;
    if (s.size() != t.size())
        return false;
    int umap[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
        umap[s[i] - 'a']++;
        umap[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (umap[i])
            return false;
    }
    return true;
}
int main()
{

    cout << isAnagram("anagram", "nagaram");
}