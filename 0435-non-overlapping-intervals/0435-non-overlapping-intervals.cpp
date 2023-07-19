class Solution {
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        int af=a[0];
        int as=a[1];
        
        int bf=b[0];
        int bs=b[1];
        
        if(as!=bs)
        {
            return as<bs;
        }
        else
        {
            return af<bf;
        }
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
        
        int n=in.size();
        
        sort(in.begin(),in.end(),cmp);
        
        
        vector<int> temp=in[0];
        
        int cnt=0;
        
        for(int i=1;i<n;i++)
        {
            int ls=temp[1];
            
            if(in[i][0]>=ls)
            {
                temp=in[i];
            }
            else
            {
                cnt++;
                continue;
            }
                
        }
        
        return cnt;
        
    }
};