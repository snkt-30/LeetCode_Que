class Solution {
public:

    vector<string>ans;

    void solve(int i, vector<string>& words, int maxwidth){
        int n=words.size();
        if(i>=n)return ;

        string temp="";
        
        int curr=i,j=i,len=0, twords=0;
        queue<int>q;

        while(i<n && len+words[i].length()<=maxwidth){
            len+=words[i].length();
            i++;
            len++; //min one gap
            twords++;
        }
        len--;
        int gap=maxwidth-len;
        int incspac=0;
        if(twords>1){
            if(gap%(twords-1)!=0){
                int k=gap%(twords-1);
            
                while(k!=0){
                    q.push(1);//inc gap b/w each word
                    k--;
                }
            }
            incspac=gap/(twords-1);
        }
        else incspac=gap;

// cout<<i<<" "<<twords<<" :"<<len<<" "<<gap<<" "<<incspac<<" "<<endl;

       if(i>=n)
       {
           //LAST LINE LEFT align
           while(j!=i-1){
           
            temp+=words[j];
            temp+=" ";
            j++;
            }

            temp+=words[j];
        
            while(gap){//POORA GAP right mei --LEFT ALIGN!!*
                temp+=" ";
                gap--;
            }

       }else{
           //ALL OTHER LINES
            while(j!=i-1){
            
                temp+=words[j];
                temp+=" ";
                
                int g=incspac;
                if(!q.empty()){
                    g+=q.front();
                    q.pop();
                }
                // cout<<g<<endl;
                while(g>0){
                    temp+=" ";
                    g--;
                }
                j++;
                //  cout<<j<<" "<<temp<<" "<<incspac<<endl;
            }

            temp+=words[j];

            //IF ONLY ONE WORD IN A LINE--add all _spaces_ in right side
            if(twords==1){
            int g=incspac;
                while(g>0){
                    temp+=" ";
                    g--;
                }   
            }
       }


        ans.push_back(temp);
        solve(i, words, maxwidth);
        return ;
    }

    vector<string> fullJustify(vector<string>& words, int maxwidth) {
        if(words.size()==1 && maxwidth==1)return {words[0]};

        solve(0, words, maxwidth);
        return ans;
    }
};