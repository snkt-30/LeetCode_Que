class Solution {
public:
    bool buddyStrings(string s, string t) {

        int n=s.length();
        int m=t.length();
        
        if(n!=m)
            return false;
        
        
             map<char,int>mp;
        
        int cnt=0;
        
        vector<int> in;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]--;
            mp[t[i]]--;
            if(s[i]!=t[i])
            {
                in.push_back(i);
                cnt++;
            }
        }
        
        for(auto x:mp)
        {
            if(x.second>0)
                return false;
        }
        
        if(cnt==0)
        {
            if(mp.size()<=(n-1))
                return true;
            return false;
        }
        
        if(cnt>2)
            return false;
        
        if(cnt==2)
        {
            swap(s[in[0]],s[in[1]]);
            
        }
        return (s==t);
        
        
        
    }
};