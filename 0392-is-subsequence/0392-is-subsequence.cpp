class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        for( i=0,j=0;i<t.length();i++)
        {
            if(s[j]==t[i])
            {
                j++;
            }
        }
        
cout<<j<<endl;
        return (j == s.length());
    }
};