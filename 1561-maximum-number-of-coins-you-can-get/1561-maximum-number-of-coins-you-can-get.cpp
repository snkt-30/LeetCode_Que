class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        
        int cnt= piles.size()/3;
        
        sort(piles.begin(),piles.end());
        
        
        int ans=0;
        
        int ind=piles.size();
        
        
        
        while(cnt--)
        {
            ind=ind-2;
            
            ans+=piles[ind];
        }
        
        return ans;
    }
};