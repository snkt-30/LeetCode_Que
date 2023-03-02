class Solution
{
    public:
        int compress(vector<char> &c)
        {

            string res = "";

            int i = 0, j = 1;

            int n = c.size();

            if (n == 1 )
                return n;

            if(n==2)
            {
                if(c[0]==c[1])
                    c[1]='2';
                
                return 2;
            }
            
            
            while (j < n)
            {
                if (c[i] == c[j])
                {
                    while (j < n and c[i]==c[j])
                    {
                        j++;
                    }

                    res.push_back(c[i]);
                    string val = to_string(j - i);
                    
                    // reverse(val.begin(), val.end());

                    int v = 0;

                    while (v < val.length())
                    {
                        res.push_back(val[v]);
                        v++;
                    }
                    i = j;
                    j++;
                }
                else
                {
                    res.push_back(c[i]);
                    i = j;
                    j++;
                }
            }
            
            
            if(i==n-1 and c[i]!=c[i-1])
            {
                res.push_back(c[i]);
            }
            
            c.clear();
            
             i=0;
            
            while(i<res.length())
            {
                c.push_back(res[i]);
                i++;
            }
            
            return i;
           
        }
};