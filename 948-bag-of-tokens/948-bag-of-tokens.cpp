class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
         int n=tokens.size();
        
        if(n==0)
        {
            return 0;
        }
        sort(tokens.begin(),tokens.end());
        
        
        if(tokens[0]>power)
            return 0;
        
        int i=0,j=n-1;
        int score=0;
        
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                score++;
                i++;
                
            }
            else if(score>0 and i<j)
            {
                score--;
                power+=tokens[j];
                j--;
            }
            else
            {
                break;
            }
        }
        
        return score;
        
        
        
    }
};