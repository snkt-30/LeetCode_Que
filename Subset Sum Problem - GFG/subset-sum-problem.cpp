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
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        
        
        // dp[0][0]=true;
        
         for(int i=0;i<=sum;i++)
         {
             dp[0][i]=false;
         }
         
         for(int i=0;i<=n;i++)
         {
             dp[i][0]=true;
         }
         
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=sum;j++)
             {
                 bool take=0;
                 
                 if(arr[i-1]<=j)
                   take=dp[i-1][j-arr[i-1]];
                   
                  bool not_take=dp[i-1][j];
                  
                 dp[i][j]=(take or not_take);
             }
         }
        
        
        return dp[n][sum];
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