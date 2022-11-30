class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n=arr.size();
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> v;
        
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])return false;
        }
        
        return true;
    }
};