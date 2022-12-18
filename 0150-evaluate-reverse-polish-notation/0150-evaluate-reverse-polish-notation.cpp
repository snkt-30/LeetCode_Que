class Solution {
    
    bool isOperator(string &t)
    {
        if(t=="/" or t=="+" or t=="*" or t=="-")
             return true;
        
        return false;
    }
public:
    int evalRPN(vector<string>& t) {
        
           stack<string> s;   
        
        for(int i=0;i<t.size();i++)
        {
            if(isOperator(t[i]))
            {
                auto a=s.top();
                s.pop();
                auto b=s.top();
                s.pop();
                int x=stoi(a);
                int y=stoi(b);
                
                int sum=0;
                if(t[i]=="/")
                {
                  sum=(y/x);
                }
                else if(t[i]=="*")
                {
                    sum=x*1LL*y;
                }
                else if(t[i]=="+")
                {
                    sum=y+0LL+x;
                }
                else
                {
                   sum=y-x;
                }
                string temp=to_string(sum);
                s.push(temp);
            }
            else
            {
                s.push(t[i]);
            }
        }
        
        auto ans=s.top();
        int res=stoi(ans);
        return res;
    }
};