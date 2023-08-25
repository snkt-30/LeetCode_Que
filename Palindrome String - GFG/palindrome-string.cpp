//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string a)
	{
	    // Your code goes here
	    
	    int l=0,r=a.length()-1;
	    
	    
	    while(l<=r)
	    {
	        if(a[l]!=a[r])
	        {
	            return 0;
	        }
	        
	        l++,r--;
	    }
	    
	    return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends