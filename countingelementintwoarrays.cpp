#include"bits/stdc++.h"
using namespace std;



  vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n){
    
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
    
    }
int main()
{

}