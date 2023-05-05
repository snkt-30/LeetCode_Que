class Solution {
public:
    int maxVowels(string s, int k) {
        
        int mx_vowel=0;
        
        
        int l=0,r=0;
        
        int n=s.length();
        
        unordered_map<char,bool> mp;
        
        mp['a']=true;
        mp['e']=true;
        mp['i']=true;
        mp['o']=true;
        mp['u']=true;
        
        int v=0;
        
        while(r<n)
        {
            if(mp[s[r]]==true)
            {
               v++;
            }
            
            if(r-l+1==k)
            {
                mx_vowel=max(mx_vowel,v);
                if(mp[s[l]]==true)
                {
                    v--;
                }
                l++;
                r++;
            }
            else
            {
                r++;
            }
        }
        return mx_vowel;
    }
};