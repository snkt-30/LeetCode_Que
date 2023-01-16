//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

#define ll long long int

class Solution 
{
    private:
    static bool isPossible(ll range,int pages[],int no_of_books,int no_of_stu)
    {
        int stu_allocated=1;
        
        ll pages_allocated=0;
        
        
        for(int i=0;i<no_of_books;i++)
        {
            if(pages[i]>range)return false;
            
            if(pages_allocated + pages[i] > range)
            {
                stu_allocated+=1;
                pages_allocated=pages[i];
            }
            else
            {
                pages_allocated += pages[i];
            }
        }
        
       if(stu_allocated > no_of_stu)return false;
        
        return true;
        
        
        
    }
    
    // let assume my guess has come 120
    // 12 46 113 203
    
    
    public:
    //Function to find minimum number of pages.
    int findPages(int pages[], int n, int m) 
    {
        //code here
        
        // condition when the allocation will not possible
        /*
        1.when the student count is greater than given books 
        */
        // if count of student will be equal to count of books the pages[n-1] will be the ans
        
        // pagez[n-1] would be the max pages of book that mean each student atleast get that much amount of book
        
        // from these we can reduced the search space from pages[n-1] to sumation of pages[];
        
        ll sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=pages[i];
        }
        
        ll lo=pages[n-1],hi=sum;
        
        ll ans=INT_MAX;
        
        if(m>n)return -1;
        
        while(lo<=hi)
        {
            
            ll mid=(hi+lo)>>1;
            
            if(isPossible(mid,pages,n,m))
            {
                ans=min(ans,mid);
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        
       return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends