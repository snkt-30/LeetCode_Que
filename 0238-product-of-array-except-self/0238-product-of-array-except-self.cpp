class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);

        left[0]=1;
        right[n-1]=1;

        cout<<left[0]<<" ";

        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];

            cout<<left[i]<<" ";
        }
        cout<<endl;

        cout<<right[n-1]<<" ";
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];

            cout<<right[i]<<" ";
        }

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            int pr=left[i]*1LL*right[i];
            ans.push_back(pr);
        }
        return ans;
    }
};