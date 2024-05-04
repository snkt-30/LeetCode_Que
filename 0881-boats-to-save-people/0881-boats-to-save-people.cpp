class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        
        int n= people.size();
        
        int i=0,j=n-1;
        
        int minRescueBoats=0;
        
        while(i<=j)
        {
            int lValue= people[i];
            int rValue = people[j];
            
            if(i==j)
            {
                minRescueBoats++;
                break;
            }
            
            if(rValue == limit){
                minRescueBoats++;
                j--;
            }
            else if((lValue + rValue) > limit)
            {
                j--;
                minRescueBoats++;
            }
            else {
                i++,j--;
                minRescueBoats++;
            }
            
            cout<<minRescueBoats<<" "<<i<<" "<<j<<endl;
        }
        
        return minRescueBoats;
        
        
    }
};