class Solution {
public:
    string minWindow(string s, string t) {
        
   unordered_map<char, int> mp;

	int ns = s.length();
	int nt = t.length();
        
        if(nt>ns)
             return "";
        
        if(ns==1 and nt==1)
        {
            if(s[0]==t[0])
                return t;
            return "";
        }

	int cnt = 0;

	for (int i = 0; i < nt; i++)
	{
		if (mp.count(t[i]) == 0)
			cnt++;
		mp[t[i]]++;
	}

	int in = 0, ls = 0;

	// set<pair<int, int>> st;
	queue<char> q;
        
        int len=INT_MAX;
        int ind=-1;
	while (ls < ns)
	{
		// precomputation
		q.push(s[ls]);
		if (mp.count(s[ls]))
		{
			mp[s[ls]]--;
			if (mp[s[ls]] == 0)
				cnt--;
		}


		if (cnt != 0)
			ls++;
		// sataisfied cond
		 if (cnt == 0)
		{
			while (cnt == 0 and in<=ls)
			{
                int curr=ls-in+1;
                if(curr < len)
                {
                    len = curr;
                        ind = in;
                }
				q.pop();
				if (mp.count(s[in]))
				{
					if (mp[s[in]] == 0)
						cnt++;
					mp[s[in]]++;
				}
				in++;
			}
            
			ls++;
		}
	}
        // --in;
        cout<<len<<" "<<ind<<endl;
        
        string res="";
        if(ind==-1)
            return res;
        
        while(len--)
        {
            res.push_back(s[ind]);
            ind++;
        }
        return res;
    }
};