#include "bits/stdc++.h"
using namespace std;

int trap(vector<int> &height)
{

    int currmx=INT_MIN;
    int mxwater=0;
    int st=height[0];

    for(int i=1;i<height.size();i++)
    {
        if(height[i]<st)
        {
            currmx+=(st-height[i]);
        }
        else if(st<height[i])
        {
            mxwater=max(mxwater,currmx);
            st=height[i];
        }
    }
    return mxwater;
}

int Trapping_Rain_Water(vector<int> &height)
{
    vector<int> left(height.size(),0), right(height.size(),0);

     left[0]=height[0];
    for(int i=1;i<height.size();i++)
    {
        left[i]=max(left[i-1],height[i]);
    }
    
    for(int i=height.size()-1;i>=0;i--)
    {
        right[i]=max(right[i+1],height[i]);
    }
    
    int ans=0;
    for(int i=0;i<height.size();i++)
    {
        ans+=(min(left[i],right[i]))-height[i];
    }

    return ans;


}
int main()
{
    vector<int> nums={4,2,0,3,2,5};

    cout<<Trapping_Rain_Water(nums);
}