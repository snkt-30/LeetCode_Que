class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        int n = word.length();
        
        map<int,int> freq;
        
        freq[0]=1;
        
        long long int mask=0;
        
        long long int res = 0;
        
        for(int i=0;i<n;i++)
        {
            char c = word[i];
            long long bit = c-'a';
            
            mask^=(1<<bit);
            
            res+=freq[mask];
            
            freq[mask]=freq[mask]+1;
            
            for(int odd_c=0; odd_c <10;odd_c++)
            {
                res+=freq[mask^(1<<odd_c)];
            }
        }
        
        return res;
    
    }
};