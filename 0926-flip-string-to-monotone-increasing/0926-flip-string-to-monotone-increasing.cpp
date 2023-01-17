class Solution {
public:
    int minFlipsMonoIncr(string s) {
    
        int n=s.length();
        
        int changes=0;
        int no_of_ones=0;
        
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(no_of_ones>0)
                {
                    changes++;
                }
            }
            else
            {
                no_of_ones++;
            }
            
            
            changes=min(changes,no_of_ones);
        }
        
        return changes;
        
        
    }
};