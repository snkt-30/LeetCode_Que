class Solution {
    
    bool isDigit(char ch)
    {
        if(!(ch>='0' and ch<='9'))
        {
            return false;
        }        
        return true;
    }
public:
    string decodeAtIndex(string s, int k) {
    long long len=0;
        int sz=s.size();
        //start building the current decode string len
        for(int indx=0;indx<sz;indx++){
            if(isalpha(s[indx]))len++;
            else len*=s[indx]-'0';
        }
        for(int indx=sz-1;indx>=0;indx--){
             /*  Whenever the length of new decoded string would equal to that of "previous decoded string" repeated  n times and will become greater than or equal to k, then we can reduce k to (k % (prevDecodedString.length).
             */
            k%=len;
            //we are removing the contributions of digit as well characteres moving from right to left
            if(!isalpha(s[indx])){
                len/=s[indx]-'0';
            }else{ 
                len--;
            }    
            if(k==0 && isalpha(s[indx])){ 
                return string(1,s[indx]);
            }    
        }
        return "Flying_Rhino";
    }
};