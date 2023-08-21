class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string pat="";
        for(int i=0;i<s.length()/2;i++)
        {
            pat+=s[i];
            // cout<<pat<<" ";
            bool check=true;
            for(int j=i+1;j<s.length();j+=i+1)
            {
                string temp=s.substr(j,i+1);
                
                if(pat!=temp)
                {
                    check=false;
                    break;
                }
                // cout<<temp<<" ";
            }
                         
                if(check)
                {
                    return true;
                } 
            // cout<<endl;
            
        }
        
        return false;
    }
};