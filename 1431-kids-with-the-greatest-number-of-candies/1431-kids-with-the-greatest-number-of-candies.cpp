class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int x) {
        
        vector<bool>res;
        
        int n=c.size();
        
        
        for(int i=0;i<n;i++)
        {
            int val=c[i]+x;
            bool flag=true;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                else
                {
                    if(c[j]>val)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            res.push_back(flag);
        }
        
        return res;
    }
};