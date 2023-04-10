class Solution {
public:
bool isValid(string s)
{
unordered_map<char,int> pr={{'(', 1},{'[',2},{'{',3},{')',-1},{']',-2},{'}',-3}};
    int n=s.length();

    stack<char> st;
    for(char x:s)
    {
        if(pr[x]>0)
        {
            st.push(x);
        }
        else 
        {
            if(st.empty())
            {
                return false;
            }

            char top=st.top();
            st.pop();

            if(pr[top]+pr[x]!=0)
            {
                return false;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    
    return true;
}
};