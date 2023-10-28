// #define ll long long int
class Solution {
public:
    typedef long long ll;
ll mod = 1e9+7;

vector<vector<ll>> dp;

// chnaging states -> idx,prev
ll func(int idx, int prev, int n){
    
    if(idx==n) return 1;
    
    if(dp[idx][prev]!=-1) return dp[idx][prev];
    
    ll ans = 0;
    
    if(prev == 1){ // a
        ans += func(idx+1,2,n);    ans%=mod;
    }
    
    if(prev == 2){ // e
        ans += func(idx+1,1,n);   ans%=mod;
        ans += func(idx+1,3,n);   ans%=mod;
    }
    
    if(prev == 3){ // i
        ans += func(idx+1,1,n);    ans%=mod;  
        ans += func(idx+1,2,n);    ans%=mod;  
        ans += func(idx+1,4,n);     ans%=mod; 
        ans += func(idx+1,5,n);     ans%=mod; 
    }
    
    if(prev == 4){ // o
        ans += func(idx+1,3,n);     ans%=mod; 
        ans += func(idx+1,5,n);     ans%=mod; 
    }
    
    if(prev == 5){ // u
        ans += func(idx+1,1,n);    ans%=mod;
    }
    
    return dp[idx][prev] = ans;
    
}

int countVowelPermutation(int n) {
    
    ll ans = 0;
    
    dp.resize(n,vector<ll>(6,-1));
    
    for(int i=1;i<=5;i++){
        ans += func(1,i,n); ans%=mod;
    }
    
    return ans;
}

};