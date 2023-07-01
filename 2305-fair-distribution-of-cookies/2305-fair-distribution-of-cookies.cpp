class Solution {
public:
    
    int ans=INT_MAX;
    int n;
    
    void solve(int idx,vector<int>&c,vector<int>&stu,int k)
    {
        if(idx>=n)
        {
            int unfairness=*max_element(begin(stu),end(stu));
            
            ans=min(ans,unfairness);
            
            return;
        }
        
        int cook=c[idx];
        
        for(int i=0;i<k;i++)
        {
            stu[i]+=cook;
            
            solve(idx+1,c,stu,k);
            
            stu[i]-=cook;
        }
    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        n=cookies.size();
        
        vector<int> student(k,0);
        
        solve(0,cookies,student,k);
        
        return ans;
        
    }
};