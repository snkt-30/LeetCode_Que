class Solution
{
    public:
        long long zeroFilledSubarray(vector<int> &a)
        {

            long long int ans = 0;

            int l = 0, r = 0;
            int n = a.size();

            long long int cnt = 0;
            while (r < n)
            {
                if (a[r] == 0)
                {
                    cnt++;

                    if (r == n - 1)
                    {
                        ans += (cnt*1LL*(cnt + 1))/2LL;
                        break;
                    }
                }
                else
                {
                    ans += (cnt *(cnt + 1)) / 2;
                    cnt = 0;
                }

                r++;
            }

            return ans;
        }
};