class Solution {
public:
    string largestGoodInteger(string num) {
        
        int nm=0;
        bool chk=false;
        int n=num.length();
        for(int i=1;i<n-1;i++)
        {
            if(num[i-1]==num[i] and num[i]==num[i+1])
            {
                int dig=num[i]-'0';
                
                nm=max(nm,dig);
                chk=true;
            }
        }
        
        if(!chk)
        {
            return "";
        }
        
        string ans="";
        
        for(int i=0;i<3;i++)
        {
          ans+=to_string(nm);  
        }
        
        return ans;
        
    }
};