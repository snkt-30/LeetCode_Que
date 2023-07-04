class Solution {
public:
    int singleNumber(vector<int>& a) {
        
//         int tn=INT_MAX,tnp1=0,tnp2=0;
        
        int n=a.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int cwtn= tn & a[i];
//             int cwtnp1= tnp1 & a[i];
//             int cwtnp2= tnp2 & a[i];
            
//             tn = tn & (~cwtn);
//             tnp1 = tnp1 | cwtn;
            
//             tnp1 = tnp1 & (~cwtnp1);
//             tnp2= tnp2 | cwtnp1;
            
//             tnp2 =tnp2 & (~cwtnp2);
//             tn= tn | cwtnp2;
//         }
        
//         // cout<<tn<<" "<<tnp1<<" "<<tnp2<<endl;
//         return tnp1;
        
        int ones=0,twos=0;
        
        for(int i=0;i<n;i++)
        {
            ones= (ones^a[i]) & (~twos);
            twos =(twos^a[i]) & (~ones);
        }
        
        return ones;
    }
};