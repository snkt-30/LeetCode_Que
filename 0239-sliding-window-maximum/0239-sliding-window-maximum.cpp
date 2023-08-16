class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        list<int> q;
        
        
        
        int r=0,l=0;
        int n=a.size();
        
        vector<int>ans;
        
        
        while(r<n)
        {
            if(q.empty())
            {
                q.push_back(a[r]);
            }
            else
            {
                while(!q.empty() and q.back()<a[r])
                {
                    q.pop_back();
                }
                q.push_back(a[r]);
                // cout<<q.back()<<" "<<r<<" "<<q.front()<<endl;
            }
            if(r-l+1 == k)
            {
                ans.push_back(q.front());
                
                if(q.front() == a[l])
                {
                    q.pop_front();
                }
               l++;
            }
            r++;
        }
        
        return ans;
    }
};