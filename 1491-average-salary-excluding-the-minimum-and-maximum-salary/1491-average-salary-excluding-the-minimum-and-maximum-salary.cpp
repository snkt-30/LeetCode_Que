class Solution {
public:
    double average(vector<int>& a) {
        
        sort(a.begin(),a.end());
        
        int n=a.size();
        
        
        double add=0.00000;
        
        for(int i=1;i<n-1;i++)
        {
            add+=a[i];
        }
        
        add=add/(double)(n-2);
        
        return add;
    }
};