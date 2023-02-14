class Solution {
public:
    string addBinary(string a, string b) {
        
        int an=a.length();
        int bn=b.length();
        
        
        if(!an)
            return b;
        
        if(!bn)
            return a;
        
        string ans="";
        
        --an,--bn;
        
        int carry=0;
        char one='1';
         char zero='0';
        
        while(an>=0 and bn>=0)
        {
            string t=to_string(carry);
            if(a[an]=='0' and b[bn]=='0')
            {
                ans+=t;
                carry=0;
            }
            else if(a[an]=='1' and b[bn]=='1')
            {
                ans+=t;
                
                carry=1;
            }
            else
            {
                if(carry==0)
                {
                    
                    ans.push_back(one);
                    carry=0;
                }
                else
                {
                   
                    ans.push_back(zero);
                    carry=1;
                }
            }
            
            an--;
            bn--;
                  
        }
        
        while(an>=0)
        {
            if(a[an]=='0')
            {
                if(carry==1)
                {
                    
                    ans.push_back(one);
                    carry=0;
                }
                else
                {
                    // string zero=to_string('0');
                    ans.push_back(zero);
                }
            }
            else
            {
                if(carry==1)
                {
                    // string zero=to_string('0');
                    ans.push_back(zero);
                    carry=1;
                }
                else
                {
                    ans.push_back(one);
                }
            }
            an--;
        }
        
        while(bn>=0)
        {
            
            if(b[bn]=='0')
            {
                if(carry==1)
                {
                    ans.push_back(one);
                    carry=0;
                }
                else
                {
                    ans.push_back(zero);
                }
            }
            else
            {
                if(carry==1)
                {
                    ans.push_back(zero);
                    carry=1;
                }
                else
                {
                    ans.push_back(one);
                }
            }
            --bn;
        }
        
        if(carry==1)
        {
            ans.push_back(one);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};