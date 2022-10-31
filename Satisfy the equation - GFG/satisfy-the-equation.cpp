//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        
        vector<int>ans;
        
        for(int i=0;i<N;i++)
        {
            if(ans.size()!=0)
              break;
            for(int j=0;j<N;j++)
            {
                if(ans.size()!=0) break;
                for(int k=0;k<N;k++)
                {
                    if(ans.size()!=0)break;
                    for(int l=0;l<N;l++)
                    {
                        if(i!=j and i!=k and i!=l and j!=k and j!=l and k!=l)
                           if(ans.size()==0)
                           {
                               if(A[i]+A[j]==A[k]+A[l])
                               {
                                   ans.push_back(i);
                                   ans.push_back(j);
                                   ans.push_back(k);
                                   ans.push_back(l);
                               }
                           }
                       }
                    }
                }
            
        }
        
        if(ans.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends