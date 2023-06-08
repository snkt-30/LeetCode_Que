class Solution {
public:
     int CountNeg( vector<int> row, int n ) {
        int lo = 0, hi = n-1, mid;
        
        while( lo < hi ) {
            mid = lo + ( hi - lo )/2;
            if( row[mid] >= 0 )
                lo = mid + 1;
            else
                hi = mid;
        }
        if( row[lo] < 0 )
            return (n - lo);
        return 0;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        if( grid.empty() || grid[0].empty() )
            return 0;
        
        int n = grid[0].size(), count = 0;
        for( auto row : grid )
            count += CountNeg(row, n);
        return count;
    }
};