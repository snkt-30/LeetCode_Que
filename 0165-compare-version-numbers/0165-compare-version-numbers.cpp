class Solution {
public:
    int compareVersion(string a, string b) {
        
        int n= a.length();
        int m = b.length();
        
        int i=0,j=0;
        
        while(i<n and j<m)
        {
            int v1 =0,v2=0;
            
            while(i<n and a[i]!='.')
            {
                v1 = v1*10 + (a[i]-'0');
                i++;
            }
            
            while(j<m and b[j]!='.')
            {
                v2 = v2*10 + (b[j]-'0');
                j++;
            }
            
            cout<<v1<<" "<<v2<<endl;
            if(v1 == v2)
            {
                i++;
                j++;
            }
            else if(v1 < v2)
            {
               return -1; 
            }
            else
            {
                return 1;
            }        
        }
        
        while(i<n)
        {
            int v1 =0;
            
            while(i<n and a[i]!='.')
            {
                v1 = v1*10 + (a[i]-'0');
                i++;
            }
            
            if(v1==0)
            {
                i++;
            }
            else if(v1 > 0)
            {
                return 1;
            }
        }
        
        while(j<m)
        {
            int v1 =0;
            
            while(j<m and b[j]!='.')
            {
                v1 = v1*10 + (b[j]-'0');
                j++;
            }
            
            if(v1==0)
            {
                j++;
            }
            else if(v1 > 0)
            {
                return -1;
            }
        }

        
        return 0;
    }
};