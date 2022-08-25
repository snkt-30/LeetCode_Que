#include"bits/stdc++.h"
using namespace std;

// 1<= N<=1e5
  vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n){
    
    // O(N);
    vector<int> count(100001,0);

    for(int i=0;i<n;i++)
    {
        count[arr2[i]]+=1;
    }
    
    int sz=count.size();
    
    for(int i=1;i<sz;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    
    
    vector<int>ans;
    for(int i=0;i<m;i++)
    {
        int x=count[arr1[i]];
        ans.push_back(x);
    }
    
    return ans;
    
    // second approach 
//      vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n) {
        
//         vector<int> ans;
//         sort(arr2, arr2+n);
//         for(int i=0; i<m; i++) {
//             int num = upper_bound(arr2, arr2 + n, arr1[i]) - arr2;
//             ans.push_back(num);
//         }
//         return ans;
//     }
    
    }
int main()
{

}
