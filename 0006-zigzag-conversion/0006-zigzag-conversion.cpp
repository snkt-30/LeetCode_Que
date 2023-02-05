class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<vector<char>> mat(numRows,vector<char>(1001,'#'));
        
        
        bool flag=true;
        
        int ind=0;
        
        int n=s.length();
        
        if(n<=2 or numRows>=n or numRows==1)
                return s;

        int row=0,col=0;
        
        while(ind<n)
        {
            mat[row][col]=s[ind];
        
            if(flag)
            {
                row++;          
                if(row==numRows-1)
                    flag=false;
            }
            else
            {           
                row--;
                col++;
                if(row==0)
                    flag=true;
            }
            ++ind;
        }
        
        string ans="";
        
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                if(mat[i][j]!='#')
                    ans+=mat[i][j];
            }
        }
        
        return ans;
    }
};