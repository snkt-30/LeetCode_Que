class Solution {
public:
    int addDigits(int num) {
        
        
        if(num<10)
            return num;
        
        while(num>=10)
        {
            int n=num;
            
           int temp=0;
            
            while(n)
            {
                temp+=n%10;
                n/=10;
            }
            num=temp;
        }
        
        return num;
    }
};