class Solution
{
    public:
        int numRescueBoats(vector<int> &p, int lm)
        {

            
            sort(p.begin(), p.end());
            
            int n=p.size();
            
         int l=0,r=n-1;
            
            
        int boat=0;
            
            while(l<=r)
            {
                boat++;
                
                if(p[l]+p[r]<=lm)
                    l++;
                r--;
            }
            return boat;
            
            
           	//         int boat_req=1;

           	//         int cnt=1;

           	//         int wt_rem=l-p[0];

           	//         for(int i=1;i < n;i++)
           	//         {
           	//             if(wt_rem>=p[i] and cnt < 2)
           	//             {
           	//                 cnt++;
           	//                 wt_rem=wt_rem-p[i];
           	//             }
           	//             else
           	//             {
           	//                 cnt=1;
           	//                 wt_rem=l-p[i];
           	//                 boat_req++;
           	//             }
           	//         }

           	//         return boat_req;
        }
};