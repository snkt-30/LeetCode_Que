class Solution {
public:
   int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        while(i!=j){
            int l=j-i+1;
            if(s[i]!=s[j])return l;
            char c=s[i];
            while(s[i]==c && i<j)i++;
            while(s[j]==c && i<j)j--;
            if(i<j)continue;
            if(i==j && s[i]!=c)continue;
            if(l==1)return 1;
            return 0;
        }
        return j-i+1;
    }
};