class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
         int R = A.size(), C = A[0].size();
        vector<vector<int>> ans(C,vector<int>(R));
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                ans[c][r] = A[r][c];
            }
        return ans;  
    }
};