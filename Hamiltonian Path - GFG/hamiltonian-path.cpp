//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int cnt=0;
    void dfs(int tar,vector<int> ls[],vector<int>& vis,int node,int count)
    {
        
       
            //increase the count
         if(count==tar){
           cnt++;
            return;
         }
        
        vis[node]=1;
        for(auto x:ls[node])
        {
            if(!vis[x])
            {
                vis[x]=1;
                dfs(tar,ls,vis,x,count+1);
            }
        }
        vis[node]=0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        
        vector<int> ls[N+1];
        
        vector<int> vis(N+1,0);
        
        for(int i=0;i<M;i++)
        {
            int x=Edges[i][0];
            int y=Edges[i][1];
            
            ls[x].push_back(y);
            ls[y].push_back(x);
        }
        
        for(int i=1;i<=N;i++)
        {
        dfs(N,ls,vis,i,1);
        }
        
        return cnt;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends