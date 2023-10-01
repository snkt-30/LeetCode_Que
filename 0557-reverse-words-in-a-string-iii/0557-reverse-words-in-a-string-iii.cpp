class Solution {
public:
    string reverseWords(string s) {
        
        string res="";
        
        int n=s.length();
        
        int l=0,r=0;
        
        while(r<n)
        {
            if(r==n-1)
            {
                string temp=s.substr(l,r-l+1);
                reverse(temp.begin(),temp.end());
                res+=temp;
            }
            else if(s[r]==' ')
            {
                string temp=s.substr(l,r-l);
                reverse(temp.begin(),temp.end());
                res+=temp;
                res+=" ";
                l=r+1;
            }
            
            r++;
            
        }
        
        return res;
    }
};