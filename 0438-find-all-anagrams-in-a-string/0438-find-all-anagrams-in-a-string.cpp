class Solution {
    
    private:
    
    static bool check(vector<int>&a,vector<int>&b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])return false;
        }
        
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> freq_s(26,0),freq_p(26,0);
        
        int n=s.length();
        
        vector<int>ans;
        
        
        for(char c:p)
        {
            freq_p[c-'a']++;
        }
        
        int l=0,r=0;
        
        int pn=p.length();
        
        while(r<n)
        {
            freq_s[s[r]-'a']++;
            
            
            if(r-l+1==pn)
            {
                if(check(freq_s,freq_p)==true)
                {
                    ans.push_back(l);
                }
            }
            
            if(r-l+1<pn)
                r++;
            else
            {
                freq_s[s[l]-'a']--;
                l++;
                r++;
            }
 
        }
    
        return ans;
        
    }
};