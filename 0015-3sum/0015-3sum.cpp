struct hashFunction 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      
        
        unordered_set<vector<int>, hashFunction> s;
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            
            int st=i+1,end=n-1;
            int fi=nums[i];
            int req=-fi;
            // vector<int>temp;
            while(st<end)
            {
                if(nums[st]+nums[end]==req)
                {
                   s.insert({fi,nums[st],nums[end]});
                    // temp.clear();
                    st++;
                    end--;
                }
                else if(nums[st]+nums[end]>req)
                    end--;
                else 
                     st++;
            }
        }
        vector<vector<int>> ans;
        
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};