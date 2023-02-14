class Solution
{
    public:
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {

            int n = rooms.size();

             vector<int> visited_rooms(n, 0);

            visited_rooms[0] = true;

            queue<int> bfs;

            bfs.push(0);

            while (!bfs.empty())
            {
                int node = bfs.front();
                bfs.pop();

                for (auto x: rooms[node])
                {
                    if (visited_rooms[x] == false)
                    {
                        visited_rooms[x] = true;
                        bfs.push(x);
                    }
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(visited_rooms[i]==0)
                    return false;
            }
            
            return true;
        }
};