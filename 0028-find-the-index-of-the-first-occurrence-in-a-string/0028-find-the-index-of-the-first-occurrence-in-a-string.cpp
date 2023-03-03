class Solution
{
    private:

        bool check(int l, int r, string h, string n)
        {
            int ind = 0;
            for (int i = l; i <= r; i++)
            {
                if (n[ind] != h[i])
                    return false;

                ++ind;
            }
            return true;
        }

    public:
        int strStr(string h, string n)
        {
            int ans = -1;

            if (h.length() < n.length())
                return -1;

            if (h.length() == n.length())
            {
                if (h == n)
                    return 0;
                return -1;
            }

            int l = 0, r = 0;

            while (r < h.length())
            {

                if (r - l + 1 < n.length())
                    r++;
                else if (r - l + 1 == n.length())
                {
                    if (check(l, r, h, n))
                    {
                        ans = l;
                        break;
                    }
                    l++;
                    r++;
                }
            }

            return ans;
        }
};