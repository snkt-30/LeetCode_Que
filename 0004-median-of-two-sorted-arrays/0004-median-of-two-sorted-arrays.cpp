class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        
        
        if(num2.size()<num1.size())return findMedianSortedArrays(num2,num1);
        
        int n1=num1.size();
        int n2=num2.size();
   
        int lo=0,hi=n1;
        
        while(lo<=hi)
        {
            int cut1=(lo+hi)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1= cut1==0?INT_MIN:num1[cut1-1];
            int left2= cut2==0?INT_MIN:num2[cut2-1];
            
            int right1= cut1==n1?INT_MAX:num1[cut1];
            int right2= cut2==n2?INT_MAX:num2[cut2];
            
            if(left1<=right2 and left2<=right1)
            {
                if((n1+n2)%2==0)
                {
                    return ((max(left1,left2)+min(right1,right2))/2.0);
                }
                else
                {
                    return (max(left1,left2));
                }
            }
            else if(left1>right2)
            {
                hi=cut1-1;
            }
            else
            {
                lo=cut1+1;
            }
        }
        
        return 0.0;
        
    }
};
