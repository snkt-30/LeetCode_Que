
#define mk make_pair
class Solution
{

    private:

        bool isValid(int row, int col, int r, int c)
        {
            return (row >= 0 and row < r and col >= 0 and col < c);
        }

    int bfs(int row, int col, vector<vector < int>> &a, vector< vector< int>> &vis)
    {
        queue<pair<int,int>> bfs;
        
        int n=a.size();
        int m=a[0].size();
        
        bfs.push(mk(row,col));
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        
        int cnt=0;
        
        bool flag=true;
        
        while(!bfs.empty())
        {
            int row=bfs.front().first;
            int col=bfs.front().second;
            
            vis[row][col]=true;
            
            cnt++;
            if(row==0 or row==n-1 or col==0 or col==m-1)
            {
                flag=false; 
            }     
            bfs.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(isValid(nrow,ncol,n,m) and !vis[nrow][ncol] and a[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=true;
                    bfs.push(mk(nrow,ncol));
                }
            }
        }
        
        if(!flag)return 0;
        
        return cnt;
    }
    
    
    public:
        int numEnclaves(vector<vector < int>> &a)
        {

            int n = a.size();
            int m = a[0].size();

            vector<vector < int>> vis(n, vector<int> (m, 0));

            int Enc = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 1 and !vis[i][j])
                    {
                        Enc += bfs(i, j, a, vis);
                    }
                }
            }
            
            return Enc;
        }
};