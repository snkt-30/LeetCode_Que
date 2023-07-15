class Solution {
    
   static bool cmp(vector<int>&a,vector<int>&b)
    {
        
        int af=a[0];
        int al=a[1];
        
        int bf=b[0];
        int bl=b[1];
        
        if(al!=bl)
        {
            return al<bl;
        }
        else
        {
          return  af<bf;
        }
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        
        
        sort(events.begin(),events.end(),cmp);
        
        int n=events.size();
        
        int l_day=events[n-1][1];
        
        set<int>day;
        
        int cnt=0;
        
        for(int i=1;i<=l_day;i++)
        {
            day.insert(i);
        }
        
        for(auto x:events)
        {
            int f=x[0];
            int l=x[1];
            
            auto it=day.lower_bound(f);
            
            if(it==day.end() or *it>l)
            {
                continue;
            }
            else
            {
                cnt++;
                day.erase(it);
            }
        }
        return cnt;
    }
};