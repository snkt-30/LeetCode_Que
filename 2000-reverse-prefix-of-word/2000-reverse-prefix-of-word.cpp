class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int indx=-1;
        
        if(word[0] == ch)
        {
            return word;
        }
        int n= word.length();
        
        for(int i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                indx=i;
                break;
            }
        }
        
        string ans ="";
        
        if(indx!=-1)
        {
            string temp = word.substr(0,indx+1);
            
            reverse(temp.begin(), temp.end());
            ans=temp;
            
            ans= ans+ word.substr(indx+1,(n-indx+1)) ;
        }
        else
        {
            return word;
        }
        
        return ans;
    }
};