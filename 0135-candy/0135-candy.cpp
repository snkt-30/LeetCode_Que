class Solution {
public:
    int candy(vector<int>& ra) {
        int n = ra.size();
        int x = n;
        int y = 0;
        int z = 0;
        int t = 0;
        for(int i = 1 ; i<n; i++)
        {
            if(ra[i] > ra[i-1])
            {
                z = 0;
                t = 0;
                y++;
                x += y;
            }
            else if(ra[i] < ra[i-1])
            {
                if(y > 0) t = y;
                z++;
                if(z >= t && t > 0) 
                {
                    t = 0;
                    z++;
                }
                if(y == 0) x += z;
                else z--;
                y = 0;
            }
            else
            {
                z = 0;
                y = 0;
            }
        }
        return x;       
    }
};