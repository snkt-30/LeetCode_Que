class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        
        int pr_x=points[0][0];
        int pr_y=points[0][1];
        
        
        int n=points.size();
        
        int ans=0;
        
        
        for(int i=1;i<n;i++)
        {
            int cr_x=points[i][0];
            int cr_y=points[i][1];
            
            int mx=max(abs(pr_x-cr_x), abs(pr_y-cr_y));
            
            ans+=mx;
            
            pr_x=cr_x;
            pr_y=cr_y;
        }
        
        return ans;
    }
};