class Solution {
public:
    static constexpr int mod = 1'000'000'007;
    int numMusicPlaylists(int n, int goal, int k) {
        std::vector<int> dp(n);
        long long curr = 1LL;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 0; j < std::min(n, i); ++j) {
                long long prev = curr;
                curr = dp[j];
                dp[j] = (prev * (n - j)) % mod;
                if (j >= k) {
                    dp[j] += (curr * (j + 1 - k)) % mod;
                    dp[j] %= mod;
                }
            }
            curr = 0LL;
        }
        return dp.back();
    }
};