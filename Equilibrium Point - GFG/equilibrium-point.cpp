//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long int sum=0;
        long long int curr=0;
        
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        
        for(int i=0;i<n;i++)
        {
            // cout<<curr<<endl;
            if(curr==(sum-(curr+a[i])))
            {
                return (i+1);
            }
            curr=curr+a[i];
            
            // cout<<curr<<endl;
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends