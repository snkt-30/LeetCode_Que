//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        vector<char> uc,lc;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' and s[i]<='z')
            {
                lc.push_back(s[i]);
            }
            else
            {
                uc.push_back(s[i]);
            }
        }
        
        sort(uc.begin(),uc.end());
        sort(lc.begin(),lc.end());
        
        int l_ind=0,u_ind=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' and s[i]<='z')
            {
                s[i]=lc[l_ind];
                l_ind++;
            }
            else
            {
                s[i]=uc[u_ind];
                u_ind++;
            }
        }
        return s;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends