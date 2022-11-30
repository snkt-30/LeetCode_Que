class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n=arr.size();
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        // vector<int> v;
        
        unordered_set<int>st;
        
        for(auto x:mp)
        {
            if(st.count(x.second))return false;
            st.insert(x.second);
        }
        
        return true;
    }
};