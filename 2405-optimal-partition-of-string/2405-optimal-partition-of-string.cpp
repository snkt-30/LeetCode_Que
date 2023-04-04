class Solution {
public:
    int partitionString(string s) {
        
        int i=0,j=0;
        int n=s.length();
        
         vector<int> mp(26,0);
        
        int cnt=1;
        
        while(j<n)
        {
            mp[s[j]-'a']++;
            
            if(mp[s[j]-'a']>1)
            {
                cout<<j<<" "<<s[j]<<endl;
                cnt++;
                
                while(i<j and i<n)
                {
                    mp[s[i]-'a']--;
                    i++;
                }
                // mp[s[j]-'a']++;
            }
            j++;
        }
        
        return cnt;
    }
};