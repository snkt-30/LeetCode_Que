class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        
        
        int i=1,j=n-2;
        
        while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(arr[mid]> arr[mid-1] and arr[mid]<arr[mid+1])
            {
                i=mid+1;
            }
            else if(arr[mid]>arr[mid+1] and arr[mid]<arr[mid-1])
            {
              j=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return i;
    }
};