class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());
            vector<vector < int>> ans;

            vector<int> temp = intervals[0];

            int n = intervals.size();

            for (int i = 0; i < n; i++)
            {
                int fi = intervals[i][0];
                int se = intervals[i][1];
                int e = temp[1];
                if (fi <= e)
                {
                    temp[1] = max(e, se);
                }
                else
                {
                    ans.push_back(temp);
                    temp = intervals[i];
                }
            }
            ans.push_back(temp);
            return ans;
        }
};