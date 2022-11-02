//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumStep(int n){
        //complete the function here
        int temp=n;
        int cnt=0;
        while(temp>1){
            if(temp%3==0){
                temp/=3;
                cnt++;
            }
            else if(temp%3!=0){
                temp-=1;
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends