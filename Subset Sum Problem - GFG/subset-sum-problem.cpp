//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    
    private:
    bool helper(vector<int>&arr,int n,int s, vector<vector<int>>&dp)
    {
        if(n==0 and s==0)
          return true;
          
          if(n==0 and s>0)
            return false;
            
        if(s==0)
          return true;
          
          
          if(dp[n][s]!=-1)
            return dp[n][s];
          
          int take=0;
          
          if(arr[n-1]<=s)
          {
              take=helper(arr,n-1,s-arr[n-1],dp);
          }
          
          int not_take=helper(arr,n-1,s,dp);
          
         return dp[n][s]=(take or not_take);
    }
public:
      
    bool isSubsetSum(vector<int>&arr, int sum){
        // code here 
        
        int n=arr.size();
        
        // memset(dp,-1,sizeof(dp));
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return helper(arr,arr.size(),sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends