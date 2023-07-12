//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[101][101];
    int f(int i,int j,int arr[])
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn=1e9;
        for(int k=i;k<j;k++)
        {
            int ans=arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr);
            
            mn=min(mn,ans);
        }
        
        return dp[i][j]= mn;
        
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        return f(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends