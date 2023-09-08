class Solution {
public:
        vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for(int i=0;i<numRows;i++){
             vector<int> row(i+1);
            for(int j=0;j<i+1;j++){
                if(j>0&&j<i){
                    row[j] = pascal[i-1][j]+pascal[i-1][j-1];
                }else{
                    row[j]=1;
                }
            }
            pascal[i]=row;
        }
        return pascal;
        
    }
};