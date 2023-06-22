class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        
        
        int obsp=-a[0];
        int ossp=0;
        
        int n=a.size();
        
        for(int i=1;i<n;i++)
        {
            
            int nbsp=0;
            int nssp=0;
            
            if(ossp-a[i]>obsp)
            {
                nbsp=ossp-a[i];
            }
            else
            {
                nbsp=obsp;
            }
            
            if(a[i]+obsp-fee>ossp)
            {
                nssp=a[i]+obsp-fee;
            }
            else
            {
                nssp=ossp;
            }
            
            obsp=nbsp;
            ossp=nssp;
        }
        
        return ossp;
    }
};