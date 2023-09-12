class Solution {
public:
    int minDeletions(string s) {
        
        vector<int>freq(26,0);
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        
        vector<int>f;
        unordered_map<int,bool>check;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=1)
            {
                f.push_back(freq[i]);              
            }
        }
        
        sort(f.begin(),f.end());
        
        int ans=0;
        for(int i=f.size()-1;i>=0;i--)
        {
            int val=f[i];
            cout<<val<<endl;
            if(check[val]==true)
            {
                for(int j=val-1;j>=0;j--)
                {
                    if(check[j]==false)
                    {
                        if(j==0)
                        {
                            ans+=(val-j);
                        }
                        else
                        {
                            ans+=(val-j);
                            check[j]=true;
                        }
                        
                        break;
                    }
                }
            }
            else
            {
                check[val]=true;
            }
        }
        return ans;
    }
};