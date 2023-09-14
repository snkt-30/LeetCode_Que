class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adjlist;
        vector<string> res{"JFK"};
        int n = tickets.size();

        sort(tickets.begin(), tickets.end());

        for (auto ticket: tickets)
        {
            string src = ticket[0];
            string dst = ticket[1];
            adjlist[src].push_back(dst);
        }
        
        dfs(res, adjlist, "JFK", n);
        return res;
    }
    bool dfs(vector<string>& res, unordered_map<string, deque<string>>& adjlist, string cur, int n)
    {
        if (res.size() == n + 1)
            return true;

        if (adjlist.find(cur) == adjlist.end())
            return false;
        
        deque<string> tmp = adjlist[cur];
        while (!tmp.empty())
        {
            string dst = tmp.front();
            tmp.pop_front();

            res.push_back(dst);
            adjlist[cur].pop_front();

            if (dfs(res, adjlist, dst, n))
                return true;
            
            res.pop_back();
            adjlist[cur].push_back(dst);
        }
        return false;
    }
};