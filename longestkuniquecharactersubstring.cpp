#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int cnt=0;
        int i=0,j=0;
        
        unordered_map<char,int> mp;
        
        int ans=-1;
        while(j<s.length() and i<=j)
        {
           if(mp.find(s[j])==mp.end() or mp[s[j]]==0)
           {
               cnt++;
           }
           mp[s[j]]++;
            
            if(cnt<k) // when the substring contain less that k unique char
            {
                j++;
            }
            else if(cnt==k) // when the we match the condition 
            {
              ans=max(ans,j-i+1);
              j++;
            }
            else if(cnt>k) // when the condition exceed
            {
                while(cnt>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        cnt--;
                      
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
