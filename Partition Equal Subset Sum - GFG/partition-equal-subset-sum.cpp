//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[101][10001];
    
    int helper(int ind,int arr[],int n,int tar)
    {
        if(ind==n)
        {
            if(tar==0)
              return 1;
              
              return 0;
        }
        
        if(dp[ind][tar]!=-1)
        {
            return dp[ind][tar];
        }
        
        int take=0,not_take=0;
        
        if(tar>=arr[ind])
          take=helper(ind+1,arr,n,tar-arr[ind]);
          
        not_take=helper(ind+1,arr,n,tar);
        
        return dp[ind][tar]=(take or not_take);
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        
        memset(dp,-1,sizeof(dp));
        
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum&1)
        {
            return 0;
        }
        
        return helper(0,arr,N,sum/2);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends