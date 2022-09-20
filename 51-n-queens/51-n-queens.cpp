class Solution {
public:
    
    
    bool isSafe(int row,int col,vector<string>&board,int n)
    {
        // for upper daigonal
        
        int uppdai_row=row;
        int uppdai_col=col;
        
        while(uppdai_row>=0 and uppdai_col>=0)
        {
            if(board[uppdai_row][uppdai_col]=='Q')return false;
            uppdai_row--;
            uppdai_col--;
        }
        
        // for left in the row
        
        int left_col=col;
        while(left_col>=0)
        {
            if(board[row][left_col]=='Q')return false;
            left_col--;
        }
        
        // for lowerleft daigonal
        int left_dai_row=row;
        int left_dai_col=col;
        
        while(left_dai_row<n and left_dai_col>=0)
        {
            if(board[left_dai_row][left_dai_col]=='Q')return false;
            left_dai_row++;
            left_dai_col--;
        }
        
        return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
           board[i]=s; 
        }
        solve(0,board,ans,n);
        
        return ans;
   }
};