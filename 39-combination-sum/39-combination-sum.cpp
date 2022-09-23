class Solution {
public:
    void combo(int ind,vector<vector<int>>&ans,vector<int>&ds,vector<int>&ar,int target)
    {
        
        
      if(target==0)
      {
          ans.push_back(ds);
          return;
      }
        if(target<0)
            return;
        
        if(ind==ar.size())
            return;
           combo(ind+1,ans,ds,ar,target);
        
          ds.push_back(ar[ind]);
          combo(ind,ans,ds,ar,target-ar[ind]);
          ds.pop_back();
          
        
//         //if our target becomes zero at any point, then yess!! we wil find a possible combination
//         if(target == 0) 
//         {
//             ans.push_back(temp); // include that combination in our answer
//             return; // and then return, we are now not gonna explore more possiblity
//         }
        
//         // if at any point target becomes less than zero, then simply return, saying that no it is notpossible to our target combination sum
//         if(target < 0)
//             return;
        
//         // if index crosses the last index, we will return saying that no more element is left to choosee
//         if(i == arr.size())
//             return;
        
//         // As we dicussed for every element we have two choices whether to include in our answer or not include in our answer. 
// 		//so now, we are doing that
        
//         // we are not taking the ith element,
//         // so without decreasing sum we will move to next index because it will not contribute in making our sum
//         solve(i + 1, arr, temp, target);
        
//         // we are taking the ith element and not moving onto the next element because it may be possible that this element again contribute in making our sum.
//         // but we decrease our target sum as we are consediring that this will help us in making our target sum
        
//         temp.push_back(arr[i]); // including ith element
//         solve(i, arr, temp, target - arr[i]); // decreasing sum,and call again function
//         temp.pop_back(); // backtrack
      
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        combo(0,ans,ds,candidates,target);
        return ans;
    }
};