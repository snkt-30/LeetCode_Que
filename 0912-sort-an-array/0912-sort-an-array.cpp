class Solution {
    
    private:
    
    void merge(int l,int mid,int r,vector<int>&a)
    {
        int l_size=mid-l+1;
        
        int r_size=r-mid;
        
        vector<int> left(l_size+1);
        vector<int>right(r_size+1);
        
        left[l_size]=right[r_size]=INT_MAX;
        
        for(int i=0;i<l_size;i++)
        {
            left[i]=a[l+i];
        }
        
        for(int i=0;i<r_size;i++)
        {
            right[i]=a[mid+1+i];
        }
        
        int l_ind=0,r_ind=0;
        for(int i=l;i<=r;i++)
        {
            if(left[l_ind]<right[r_ind])
            {
                a[i]=left[l_ind];
                l_ind++;
            }
            else
            {
                a[i]=right[r_ind];
                r_ind++;
            }
        } 
    }
    
    
    void mergeSort(int st,int ls,vector<int>&a)
    {
        if(st<ls)
        {
            int mid=(st+ls)/2;
            
            mergeSort(st,mid,a);
            mergeSort(mid+1,ls,a);
            
            merge(st,mid,ls,a);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        
        int n=nums.size();
        
        vector<int> res(nums.begin(),nums.end());
        
        mergeSort(0,n-1,res);
        
        
        return res;
    }
};