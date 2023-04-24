class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        
        priority_queue<int> pq;
        
        for(auto x:a)
        {
            pq.push(x);
        }
        
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            
            if(a!=b)
            {
                pq.push(a-b);
            }
        }
        
        if(pq.size()==0)
            return 0;
        return pq.top();
        
        
    }
};