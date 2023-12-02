class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> mp;
        
        
        for(char & ch:chars)
        {
            mp[ch]++;
        }
        
        int ans=0;
        
        for(auto x:words)
        {
            map<char,int> freq;
            
            for(auto ch:x)
            {
                freq[ch]++;
            }
            bool check=true;
            
            for(auto ele:freq)
            {
                char c=ele.first;
                int cnt=ele.second;
                
                if(mp[c]<cnt)
                {
                    check=false;
                    break;
                }
            }
            
            if(check)
            {
                ans+=x.length();
            }
        }
        
        return ans;
        
    }
};