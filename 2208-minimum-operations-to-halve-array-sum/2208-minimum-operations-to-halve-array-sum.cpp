class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        
        
        double sum=0.0;
        
        priority_queue<double> pq;
        
        for(auto x:nums)
        {
            pq.push(x);
            sum+=x;
        }
        double half=sum/2.0;
        // double reduced=0.0;
        
        int oper=0;
        
        
        cout<<sum<<" "<<half<<endl;
        
        while(!pq.empty() and half>0)
        {
            
            double val=pq.top();
            pq.pop();
            
            double h=val/2.0;
            
            half-=h;
            pq.push(h);
            oper++;
            // cout<<reduced<<endl;
        }
        
        return oper;
    }
};