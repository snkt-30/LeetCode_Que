class Solution {
public:
    string mergeAlternately(string a, string b) {
        
        int n=a.length();
        int m=b.length();
        
        
        int f=0,s=0;
        
        string res="";
        
        while(f<n and s<m)
        {
            res.push_back(a[f]);
            res.push_back(b[s]);
            
            f++;
            s++;
        }
        
        while(f<n)
        {
          res.push_back(a[f]);
            f++;
        }
        
        while(s<m)
        {
            res.push_back(b[s]);
            s++;
        }
        
        return res;
    }
};