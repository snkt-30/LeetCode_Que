class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {

            vector<int> ar;
            for (int i = 0; i < nums1.size(); i++)
            {
                int x = nums1[i];
                ar.push_back(x);
            }
            for (int i = 0; i < nums2.size(); i++)
            {
                int x = nums2[i];
                ar.push_back(x);
            }

            sort(ar.begin(), ar.end());

            int n = ar.size();
            cout << fixed << setprecision(5);
            double ans = 0;
            if (n & 1)
            {
                int md = n / 2;
                ans = ar[md];
            }
            else
            {
                int md = n / 2;
                double x = ar[md] + ar[md - 1];
                ans = (x / 2);
            }
            return ans;
        }
};