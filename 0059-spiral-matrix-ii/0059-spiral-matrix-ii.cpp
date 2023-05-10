class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res (n,vector<int>(n,0));
        
        int st_row=0,st_col=0, ls_row=n-1, ls_col=n-1;
        
        int temp=n*n;
        
        int cnt=1;
        
        while(st_row<n and st_col<n and ls_row>=0 and ls_col>=0)
        {
            // for first row
            
            for(int row=st_col;row<=ls_col and temp>0;row++)
            {
                res[st_row][row]=cnt;
                cnt++;
                temp--;
            }
            st_row++;
            
            for(int col=st_row;col<=ls_row and temp>0;col++)
            {
                res[col][ls_col]=cnt;
                cnt++;
                temp--;
            }
            ls_col--;
            
            for(int row=ls_col;row>=st_col and temp>0;row--)
            {
                res[ls_row][row]=cnt;
                cnt++;
                temp--;
            }
            ls_row--;
            
            for(int col=ls_row;col>=st_row and temp>0;col--)
            {
                res[col][st_col]=cnt;
                cnt++;
                temp--;
            }
            
            st_col++;  
            
        }
        
        return res;
    }
    
    
};