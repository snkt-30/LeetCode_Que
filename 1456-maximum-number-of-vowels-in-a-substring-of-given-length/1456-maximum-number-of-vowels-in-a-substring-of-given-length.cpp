class Solution {
    private:
    
    bool check(char s)
    {
        
        return (s=='a' or s=='e' or s=='i' or s=='o' or s=='u');
    }
public:
    int maxVowels(string s, int k) {
        
        int mx_vowel=0;
        
        
        int l=0,r=0;
        
        int n=s.length();
        
//         unordered_map<char,bool> mp;
        
//         mp['a']=true;
//         mp['e']=true;
//         mp['i']=true;
//         mp['o']=true;
//         mp['u']=true;
        
        int v=0;
        
        while(r<n)
        {
            if(check(s[r]))
            {
               v++;
            }
            
            if(r-l+1==k)
            {
                mx_vowel=max(mx_vowel,v);
                if(check(s[l]))
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