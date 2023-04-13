class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        
        stack<int>st;
        
        int ind=0;
        
        int n=a.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(a[i]);
                continue;
            }
            else
            {
                if(st.top()==b[ind])
                {
                    while(!st.empty() and st.top()==b[ind])
                    {
                        st.pop();
                        ind++;
                    }
                }
                st.push(a[i]);
                
            }
        }
        
       
        while(!st.empty() and st.top()==b[ind])
        {
            st.pop();
            ind++;
        }
        
        return st.empty();
        
        
        
    }
};