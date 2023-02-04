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
    bool checkInclusion(string a, string b) {
        
        int an=a.length();
        int bn=b.length();
        
        if(an>bn)return false;
        
        vector<int>mp1(26,0),mp2(26,0);
        
        for(int i=0;i<an;i++)
        {
            mp1[a[i]-'a']++;
        }
        
        int l=0,r=0;
 
        while(r<bn)
        {
            mp2[b[r]-'a']++;
            
            
            if(r-l+1==an)
            {
                if(check(mp1,mp2)==true)
                    return true;  
            }
            
            if(r-l+1 < an)
            {
                r++;
            }
            else
            {
                mp2[b[l]-'a']--;
                l++;
                r++;            
            }
        }
        return false;
       
    }
};