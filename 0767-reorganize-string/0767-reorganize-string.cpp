class Solution {
public:
    string reorganizeString(string s) {
        
        vector<char> fill(501);
        
        map<char,int>mp;

        priority_queue<pair<int,char>> pq;
        
        int mx=0;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            
            mx=max(mx,mp[s[i]]);         
        }
        
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        if(s.length()%2==0)
        {
            if(mx>s.length()/2)
            {
                return "";
            }
        }
        else
        {
            if(mx >( s.length()/2)+1)
            {
                return "";
            }
        }
        
        int ind=0;
        
        while(!pq.empty())
        {
            char c=pq.top().second;
            // cout<<c<<endl;
            pq.pop();
            
            while(ind<s.length())
            {
                
                fill[ind]=c;
                
                ind+=2;
                
                if(ind>=s.length())
                {
                    ind=1;
                }
                
               mp[c]--;
            
                if(mp[c]==0)
                    break;
            
            }
        }
        // cout<<endl;
        
        string res="";
        
        for(int i=0;i<s.length();i++)
        {
            // cout<<fill[i]<<" ";
            res.push_back(fill[i]);
        }
        
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};