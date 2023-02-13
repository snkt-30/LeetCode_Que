class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low&1 and high&1)
        {
          return ((high-low+1)/2)+1;
        }
        else
        {
            return ((high-low+1)/2);
        }
       
    }
};