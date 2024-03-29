class Solution
{
    private:

bool isPossible(long long int tm, int total, vector<int> &a){

    long long int ans = 0;

    for (int i = 0; i < a.size(); i++)
    {
        long long int rem = tm / a[i];

        ans += rem;

        if (ans >= total)
            return true;
    }

    if (ans < total)
        return false;

    return true;
}
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long int lo = 1, hi =10000000000000000;

        while (lo < hi)
        {
            long long int mid = (lo + hi) /2;

            if (isPossible(mid, totalTrips, time))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};