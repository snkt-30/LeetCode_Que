class Solution {
public:
      string reverseWords(string s) {
        
        string ans="";
        
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
                ans+=" ";
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};