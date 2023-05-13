class Solution {
    
//     private:
    
//     int helper(int len,int a,int b,int l,int h)
//     {
        
//     }
public:
    int dp[100005];
    int countGoodStrings(int low, int high, int zero, int one) {
        dp[0] = 1;
        int mod = 1000000007;
        
        // Iterate over each length `end`.
        for (int end = 1; end <= high; ++end) {
            // check if the current string can be made by append zero `0`s or one `1`s.
            if (end >= zero) {
                dp[end] += dp[end - zero];
            }
            if (end >= one) {
                dp[end] += dp[end - one];
            }
            dp[end] %= mod;
        }
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int i = low; i <= high; ++i) {
            answer += dp[i];
            answer %= mod;
        }
        return answer;
    }
};