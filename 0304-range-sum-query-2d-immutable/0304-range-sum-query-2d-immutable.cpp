
class NumMatrix {
    // int v[210][210];
public:
    int v[210][210];

    NumMatrix(vector<vector<int>>& matrix) {
        
           int n=matrix.size();
            int m=matrix[0].size();

            for(int i=0;i<=n;i++)
                v[i][0]=0;
            for(int i=0;i<=m;i++)
               v[0][i]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                {
                    v[i][j]=matrix[i-1][j-1]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
                }
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum=v[row2+1][col2+1];

        int upper=v[row1][col2+1];
        int left=v[row2+1][col1];
        int add=v[row1][col1];

        int ans=sum-upper-left+add;
        return ans;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */