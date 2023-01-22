class Solution {
public:
    // main function that takes in a string and returns all possible partitions of the string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; // vector to store all possible partitions
        vector<string> path; // vector to store current partition
        func(0, s, res, path); // call helper function to start recursion
        return res;
     }

    // helper function that uses recursion to find all possible partitions
    void func(int ind, string s, vector<vector<string>>& res, vector<string>& path){
        if(ind == s.size()){ // base case: if we have reached the end of the string
            res.push_back(path); // add current partition to the result vector
            return ;
        }
        for(int i=ind;i<s.size();++i){ // iterate through all substrings starting from the current index
            if(isPalindrome(s, ind, i)){ // check if the current substring is a palindrome
                path.push_back(s.substr(ind, i-ind+1)); // if it is, add it to the current partition
                func(i+1, s, res, path); // call function recursively with the next index as the starting point
                path.pop_back(); // backtrack to check for other partitions
            }
        }
    }

    // helper function that checks if a substring is a palindrome
    bool isPalindrome(string s, int start, int end){
        while(start<=end){ // iterate through the substring
            if(s[start++]!=s[end--]) // check if current characters are not equal
                return false; // if they are not, return false
        }
        return true; // if we reach this point, the substring is a palindrome
    }
};