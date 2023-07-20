class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        
        stack<int> st;
        
        vector<int>res;
        
        
        int n=a.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(a[i]);
            }
            else
            {
                int top=st.top();
                int val=a[i];
                
                int top_abs=abs(top);
                int val_abs=abs(val);
                
                if(top>0 and val<0)
                {
                    while(!st.empty())
                    {
                        top = st.top();
                        top_abs = abs(top);
                        
                        if(top<0)
                        {
                            st.push(val);
                            break;
                        }
                        
                        if(top_abs > val_abs)
                        {
                            break;
                        }
                      else if(top_abs == val_abs)
                        {
                          st.pop();
                            break;
                        }
                        else if(top_abs < val_abs)
                        {
                            st.pop();
                            
                            if(st.empty()==true)
                            {
                                st.push(val);
                                break;
                            }
                        }
                    }
                }
                else
                {
                    st.push(val);
                }
            }
        }
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};