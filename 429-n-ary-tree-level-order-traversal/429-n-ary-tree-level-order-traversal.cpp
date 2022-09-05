/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {

            if (root == nullptr)
                return {};

            queue<Node*> bfs;
            bfs.push(root);

            vector<vector < int>> ans;

            while (!bfs.empty())
            {
                int n = bfs.size();
                vector<int> temp;

                for (int i = 0; i < n; i++)
                {
                    Node *node = bfs.front();
                    bfs.pop();

                    for (auto child: node->children)
                    {
                        bfs.push(child);
                    }
                    temp.push_back(node->val);
                }
                ans.push_back(temp);
            }

            return ans;
        }
};