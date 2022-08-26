#include"bits/stdc++.h"
using namespace std;


int main(){

    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }



  for(int i=0;i<n;i++)
  {
   int mn=a[i];

   int ind=i;

   for(int j=i+1;j<n;j++)
   {
      if(a[j]<a[ind])
      {
        ind=j;
      }
   }
   swap(a[i],a[ind]);

  }

  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }


    return 0;
}