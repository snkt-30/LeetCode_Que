class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        
        stack<pair<int,int>> st;
        
        int n=t.size();
        
        vector<int>ans(n);
        
       for(int i=0;i<t.size();i++)
       {
           if(st.empty())
           {
               st.push(make_pair(t[i],i));
           }
           else
           {
               if(st.top().first<t[i])
               {
                   while( !st.empty() and st.top().first<t[i])
                   {
                       int x=st.top().first;
                       int ind=st.top().second;
                       st.pop();
                       ans[ind]=(i-ind);
                   }
               }
               st.push(make_pair(t[i],i));
           }
       }
        
        while(!st.empty())
        {
            int x=st.top().second;
            ans[x]=0;
            st.pop();
        }
        return ans;
    }
};