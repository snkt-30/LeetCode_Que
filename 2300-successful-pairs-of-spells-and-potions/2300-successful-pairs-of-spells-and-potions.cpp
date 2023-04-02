
#define ll long long
class Solution
{
    public:
        vector<int> successfulPairs(vector<int> &s, vector<int> &p, long long t)
        {

           	// sort(s.begin(),s.end());

            sort(p.begin(), p.end());

            int n = s.size();
            int m = p.size();

            vector<int> res;

            for (int i = 0; i < n; i++)
            {
                ll a = s[i];

                ll l = 0, r = m - 1;

                ll ans = m;

                while (l <= r)
                {
                    int mid = (l + r) / 2;

                    ll pr = a *1LL*p[mid];

                    if (pr >= t)
                    {
                        ans = mid;
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }

                res.push_back(m - ans );
            }

            return res;
        }
};