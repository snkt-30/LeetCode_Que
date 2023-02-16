class Solution
{
    
    private:
    
    bool isValid(int nrow,int ncol,int row,int col)
    {
        return(nrow>=0 and nrow<row and ncol>=0 and ncol<col);
    }
    
    public:
        int orangesRotting(vector<vector < int>> &mat)
        {

            int n = mat.size();
            int m = mat[0].size();

            queue<pair<int, int>> bfs;

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 2)
                    {
                        bfs.push(make_pair(i, j));
                    }

                    if (mat[i][j] == 1)
                        cnt++;
                }
            }
            

            if (cnt == 0)
                return 0;

            if (bfs.size() == 0)
                return -1;
            
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,1,-1};
            
            int min_elapse=0;
            
            while(!bfs.empty())
            {
                int sz=bfs.size();
                 min_elapse++; 
                for(int i=0;i<sz;i++)
                {
                    int row=bfs.front().first;
                    int col=bfs.front().second;
                    
                    cout<<row<<" "<<col<<endl;
                    
                    bfs.pop();
                    
                    for(int del=0;del<4;del++)
                    {
                        int nrow=row+dx[del];
                        int ncol=col+dy[del];
                        
                       if(isValid(nrow,ncol,n,m) and mat[nrow][ncol] ==1)
                       {
                           mat[nrow][ncol]=2;
                           bfs.push(make_pair(nrow,ncol));
                           cnt--;
                       }
                    }
                }      
            }
          
            if(cnt>0)
                return -1;
            
            return min_elapse-1;
        }
};