class Solution {
    
    vector<vector<string>>res;
    bool Ispalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++,j--;
        }
        
        return true;
    }
    
    void solve(string s,vector<string>path,int ind)
    {
        if(ind==s.length())
        {
            res.push_back(path);
            return ;
        }
        
        
        for(int cut=ind;cut<s.length();cut++)
        {
            if(Ispalindrome(s,ind,cut))
            {
                string temp="";
                
                for(int i=ind;i<=cut;i++)
                {
                    temp+=s[i];
                }
                
                path.push_back(temp);
                
                solve(s,path,cut+1);
                
                path.pop_back();
                
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<string>path;
        
        solve(s,path,0);
        
        return res;
    }
};