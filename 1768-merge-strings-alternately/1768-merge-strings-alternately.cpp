class Solution {
public:
    string mergeAlternately(string a, string b) {
        
        int n=a.length();
        int m=b.length();
        
        if(n==0)
            return b;
        
        if(m==0)
            return a;
        
      int ind_a=0,ind_b=0;
        
        string ans="";
        
        bool flag=true;
        
        while(ind_a<n and ind_b<m)
        {
            if(flag)
            {
                ans+=a[ind_a];
                flag=false;
                ind_a++;
            }
            else
            {
                ans+=b[ind_b];
                ind_b++;
                flag=true;
            }
        }
        
        while(ind_a<n)
        {
            ans+=a[ind_a];
            ind_a++;
        }
        
        while(ind_b<m)
        {
            ans+=b[ind_b];
            ind_b++;
        }
        
        return ans;
    }
};