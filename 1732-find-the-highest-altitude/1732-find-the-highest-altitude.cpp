class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n=gain.size();
        
        int mx=0;
        int ha=0;
        
        for(int i=0;i<n;i++)
        {
            if(i>=1){
            gain[i]=gain[i]+gain[i-1];
            }
            
            mx=max(mx,gain[i]);
        }
        
        return mx;
    }
};