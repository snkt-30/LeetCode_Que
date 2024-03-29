class Solution
{
    public:
        bool validateStackSequences(vector<int> &a, vector<int> &b)
        {

            stack<int> st;

            int ind = 0;

            int n = a.size();

            for (int i = 0; i < n; i++)
            {
                st.push(a[i]);

                if (st.top() == b[ind])
                {
                    while (!st.empty() and st.top() == b[ind])
                    {
                        st.pop();
                        ind++;
                    }
                }
            }

            return st.empty();
        }
};