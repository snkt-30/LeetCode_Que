#include "bits/stdc++.h"
using namespace std;

bool isPalindrome(string s)
{
    vector<char> lower;

    if(s.length()==0)
    {
        return true;
    }

    for(int i=0;i<s.length();i++)
    {
        char chk=s[i];
        if((chk>='A' and chk<='Z') or (chk>='a' and chk<='z') or (chk>='0' and chk<='9'))
        {
            char ch=tolower(s[i]);
            lower.push_back(ch);
        }
    }

    for(int i=0;i<lower.size();i++)
    {
        if(lower[i]!=lower[lower.size()-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s="0P";

    cout<<(isPalindrome(s));
}