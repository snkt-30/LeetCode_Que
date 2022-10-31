//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int N) {
        // code here
        
        vector<int>Ans;
        
        // for(int i=0;i<N;i++)
        // {
        //     if(ans.size()!=0)
        //       break;
        //     for(int j=0;j<N;j++)
        //     {
        //         if(ans.size()!=0) break;
        //         for(int k=0;k<N;k++)
        //         {
        //             if(ans.size()!=0)break;
        //             for(int l=0;l<N;l++)
        //             {
        //                 if(i!=j and i!=k and i!=l and j!=k and j!=l and k!=l)
        //                   if(ans.size()==0)
        //                   {
        //                       if(A[i]+A[j]==A[k]+A[l])
        //                       {
        //                           ans.push_back(i);
        //                           ans.push_back(j);
        //                           ans.push_back(k);
        //                           ans.push_back(l);
        //                       }
        //                   }
        //              }
        //          }
        //       }
        //   }
        
           map<int,pair<int,int>>mp;
        
        
        // bool shouldreplace=false;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sum=a[i]+a[j];
                // pair<int,int> temp(i,j);
                if(mp.find(sum)==mp.end())
                {
                    mp[sum]=make_pair(i,j);
                    continue;
                }
                
                pair<int,int>temp=mp[sum];
                
                if(temp.first != i and temp.first != j and temp.second != i and temp.second != j)
                {
                    vector<int> ans(4);
                    
                    ans[0]=temp.first;
                    ans[1]=temp.second;
                    ans[2]=i;
                    ans[3]=j;
                    
                    if(Ans.size()==0)
                    {
                        Ans=ans;
                    }
                    else
                    {
                        bool shouldreplace=false;
                        for(int i1=0;i1<Ans.size();i1++)
                        {
                            if(Ans[i1]<ans[i1])
                              break;
                             if(Ans[i1]>ans[i1])
                             {
                                 shouldreplace=true;
                                 break;
                             }
                        }
                        
                        if(shouldreplace)
                          Ans=ans;
                    }
                }
            }
        }
        
        if(Ans.size()==0)
        {
            vector<int>a(4,-1);
            return a;
        }
        
        
        return Ans;
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