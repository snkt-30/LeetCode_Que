class Solution {
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     vector<string>ans;
    
    void gen_combo(int ind,string ds,string d)
    {
        if(ds.length()==d.length())
        {
            ans.push_back(ds);
            return;
        }
        
        string s=mp[d[ind]-'0'];
        
        for(int i=0;i<s.length();i++)
        {
            ds.push_back(s[i]);
            gen_combo(ind+1,ds,d);
            ds.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0)
        {
            return {};
        }
        
//         mp[2]="abc";
//         mp[3]="def";
//         mp[4]="ghi";
//         mp[5]="jkl";
//         mp[6]="mno";
//         mp[7]="pqrs";
//         mp[8]="tuv";
//         mp[9]="wxyz";
        
//         vector<string> st;
        
//         for(auto x:digits)
//         {
//             st.push_back(mp[x-'0']);
//         }
        
        gen_combo(0,"",digits);
        
        return ans;
        
        
    }
};