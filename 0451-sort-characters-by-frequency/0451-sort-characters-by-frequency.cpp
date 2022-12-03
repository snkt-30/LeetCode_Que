class Solution {
public:
    string frequencySort(string s) {
        
        
        map<char,int> freq;
        
        if(s.length()<3)
            return s;
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto x:freq)
        {
            pq.push(make_pair(x.second,x.first));
        }
        
        string ans="";
        
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            
            char ch= temp.second;
            int f=temp.first;
            
            cout<<ch<<" "<<f<<endl;
            for(int i=0;i<f;i++)
            {
                ans+=ch;
            }
        }
       
        return ans;
        
    }
};