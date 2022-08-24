#include "bits/stdc++.h"
using namespace std;

// 7ms  moe creative
bool isValid(string s)
{
    unordered_map<char, int> pr = {{'(', 1}, {'[', 2}, {'{', 3}, {')', -1}, {']', -2}, {'}', -3}};
    int n = s.length();

    stack<char> st;
    for (char x : s)
    {
        if (pr[x] > 0)
        {
            st.push(x);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }

            char top = st.top();
            st.pop();

            if (pr[top] + pr[x] != 0)
            {
                return false;
            }
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return true;
}

// 100 ms
bool isValidoptimized(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' or i == '{' or i == '[')
            st.push(i);
        else
        {
            if (st.empty() or (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or (st.top() == '[' and i != ']'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s = "(){}[)";

    cout << isValid(s);
}