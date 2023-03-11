//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &Q) {
        // code here
        
        vector<int> res;
        
        for(auto x:Q)
        {
            int l=x[0];
            int r=x[1];
            int k=x[2];
            
            unordered_map<int,int> mp;
            int cnt=0;
            
            for(int i=l;i<=r;i++)
            {
                mp[a[i]]++;
                
            }
            
            for(int i=r+1;i<n;i++)
            {
                if(mp.count(a[i]))
                {
                    mp[a[i]]++;
                }
            }
            
            for(int i=l;i<=r;i++)
            {
                if(mp[a[i]]==k)
                {
                    cnt++;
                }
                mp[a[i]]--;
            }
            // mp.erase();
            res.push_back(cnt);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends