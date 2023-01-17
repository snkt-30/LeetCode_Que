//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long int 


class Solution {
    
    private:
    static bool isPossible(vector<int>&stalls,int n,int k, ll range)
    {
        ll no_of_cows=1;
        ll dist=0;
        
        ll lst_pos=stalls[0];
        
        ll prev_pos=stalls[0];
        
        for(int i=0;i<n;i++)
        {
            if(dist >= range)
            {
                no_of_cows+=1;
                
                lst_pos=prev_pos;
                
                dist=abs(prev_pos-stalls[i]);
                prev_pos=stalls[i];
            }
            else
            {
                dist=abs(lst_pos-stalls[i]);
                prev_pos=stalls[i];
            }
        }
        
        if(dist>=range)
        {
            no_of_cows+=1;
        }
        
        if(no_of_cows < k)return false;
        
        return true;
        
    }
    
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        int mn=INT_MAX,mx=INT_MIN;
        
        sort(stalls.begin(),stalls.end());
        
        
        
        ll lo=1,hi=stalls[n-1]-stalls[0];
        
        ll ans=0;
        
        while(lo<=hi)
        {
            ll mid=(hi+lo)/2;
            
            if(isPossible(stalls,n,k,mid))
            {
                ans=max(ans,mid);
                 lo=mid+1;
                // cout<<ans<<" "<<mid<<endl;
            }
            else
            {
            hi=mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends