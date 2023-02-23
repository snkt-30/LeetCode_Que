//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    // private:
    
    // int helper_knapsack(int ind ,int wt[],int val[],int n,int W)
    // {
    //     if(ind==n)
    //     {
    //         if(wt[ind]<=W)
    //         {
    //             return val[ind];
    //         }
    //         return 0;
    //     }
        
    //     if(dp[ind][W]!=-1)
    //       return dp[ind][W];
        
    //     int pick=0;
        
    //     if(wt[ind]<=W)
    //       pick=val[ind]+helper_knapsack(ind+1,wt,val,n,W-wt[ind]);
           
    //      int not_pick=helper_knapsack(ind+1,wt,val,n,W);
         
    //      return dp[ind][W]= max(pick,not_pick);
    // }
    public:
    
    // int dp[1002][1002];
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
     vector<vector<int>> dp(n,vector<int>(W+1,0));
     
     for(int i=wt[0];i<=W;i++)
     {
         dp[0][i]=val[0];
     }
     
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<=W;j++)
         {
             int not_take=0+dp[i-1][j];
             
             int take=INT_MIN;
             
             if(wt[i]<=j)
             {
                 take=val[i]+dp[i-1][j-wt[i]];
             }
             
             dp[i][j]=max(not_take,take);
         }
     }
     
    return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends