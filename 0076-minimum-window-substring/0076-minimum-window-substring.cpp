class Solution {
public:
    string minWindow(string s, string t) {
        
   unordered_map<char, int> mp;

	int ns = s.length();
	int nt = t.length();

	int cnt = 0;

	for (int i = 0; i < nt; i++)
	{
		if (mp.count(t[i]) == 0)
			cnt++;
		mp[t[i]]++;
	}

	int in = 0, ls = 0;

	set<pair<int, int>> st;
	queue<char> q;
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
			while (cnt == 0)
			{
				st.insert(make_pair(ls - in + 1, in));
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

	pair<int, int> temp = *st.begin();
	st.erase(temp);
	int st_ind = temp.second;
	int sz = temp.first;

	string res = "";

	while (sz)
	{
		res.push_back(s[st_ind]);
		st_ind++;
		sz--;
	}
	return res;
    }
};