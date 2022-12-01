class Solution {
public:
    bool halvesAreAlike(string s) {
        
        
        vector<char> v={'a','e','i','o','u','A','E','I','O','U'};
        
        map<char,int>mp;
        
        for(auto x:v)
        {
            mp[x]=1;
        }
        
        int n=s.length();
        
        int left=0,right=0;
        
        for(int i=0;i<n/2;i++)
        {
            if(mp.count(s[i]))
                left++;
        }
        
        for(int i=n/2;i<n;i++)
        {
            if(mp.count(s[i]))
                right++;
        }
        
        return left==right;
    }
};