#include "bits/stdc++.h"

using namespace std;


 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=size(matrix);
        int m=size(matrix[0]);
        
        int i=0,j=m-1;
        
        while(i>=0 and i<n and j>=0 and j<m)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else 
            {
                i++;
            } 
        }
        return false;
    }
int main()
{
}