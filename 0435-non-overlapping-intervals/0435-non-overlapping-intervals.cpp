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
        
          int f=in[0][0];
          int se=in[0][1];
        
        int cnt=0;
        
        for(int i=1;i<n;i++)
        { 
            if(in[i][0]>=se)
            {
               f=in[i][0];
               se=in[i][1];
            }
            else
            {
                cnt++;
                // continue;
            }     
        }
        
        return cnt;
    }
};