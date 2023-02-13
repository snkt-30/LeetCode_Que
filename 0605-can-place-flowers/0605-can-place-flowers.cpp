class Solution
{
    public:
        bool canPlaceFlowers(vector<int> &fb, int fl)
        {

            int n = fb.size();

            if (n == 0 and fl == 0)
                return true;

            if (fl == 0)
                return true;

            if (n == 1)
            {
                if (fb[0] == 0 and n <= 1)
                    return true;
                else
                    return false;
            }

            for (int i = 0; i < n; i++)
            {
                if (fb[i] == 0)
                {
                    if (i == 0 and fb[i + 1] != 1){
                        fb[i]=1;
                        fl--;
                    }
                    else if (i == n - 1 and fb[i - 1] != 1){
                        fb[i]=1;
                        fl--;
                    }
                    else if (i>0 and i<n-1 and fb[i - 1] != 1 and fb[i + 1] != 1){
                        fb[i]=1;
                        fl--;
                    }             
                }

                if (fl == 0)
                    return true;
            }

            return false;
        }
};