class Solution {
public:
    string sortVowels(string s) {
        
        unordered_map<char,bool> mp;
        
        mp['a']=true;
        mp['e']=true;
        mp['i']=true;
        mp['o']=true;
        mp['u']=true;
        
        mp['A']=true;
        mp['E']=true;
        mp['I']=true;
        mp['O']=true;
        mp['U']=true;
        
        vector<char> ovals;
        
        for(auto x:s)
        {
            if(mp[x]==true)
            {
                ovals.push_back(x);                
                // cout<<x<<" ";
            }
            
        }
        
        
        sort(ovals.begin(),ovals.end());
        // cout<<endl;
        
        
        string res="";
        
        int ind=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==true and ind<ovals.size())
            {
                res.push_back(ovals[ind]);
                ind++;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};