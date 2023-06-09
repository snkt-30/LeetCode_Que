class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int x=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        
       int n=letters.size();
        x=x%n;
        return letters[x];
    }
};