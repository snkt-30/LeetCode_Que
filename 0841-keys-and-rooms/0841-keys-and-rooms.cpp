class Solution
{
    public:
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {

            int no_of_rooms = rooms.size();

            vector<int> visited_rooms(no_of_rooms, 0);

            visited_rooms[0] = true;

            queue<int> bfs;

            bfs.push(0);

            while (!bfs.empty())
            {
                int node = bfs.front();
                bfs.pop();

                for (auto rooms_keys: rooms[node])
                {
                    if (visited_rooms[rooms_keys] == false)
                    {
                        visited_rooms[rooms_keys] = true;
                        bfs.push(rooms_keys);
                    }
                }
            }
            
            for(int room=0;room<no_of_rooms;room++)
            {
                if(visited_rooms[room]==0)
                    return false;
            }
            
            return true;
        }
};