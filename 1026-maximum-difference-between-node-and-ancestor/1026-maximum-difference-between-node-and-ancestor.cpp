/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

	void dfs(TreeNode* node, int &mx, int &mn)
	{
		if (!node)
			return;


		mx = max(mx, node->val);
		mn = min(mn, node->val);

		dfs(node->left, mx, mn);
		dfs(node->right, mx, mn);

	}
public:
	int maxAncestorDiff(TreeNode* root) {


		if (!root)return 0;

		queue<TreeNode*> bfs;

		bfs.push(root);

		int ans = 0;

		while (!bfs.empty())
		{
			TreeNode* node = bfs.front();
			bfs.pop();
			int mn = INT_MAX, mx = INT_MIN;

			dfs(node, mx, mn);

			ans = max ( ans, max(abs(node->val - mn), abs(node->val - mx)));

			      // cout << mx << " " << mn << " " << node->val << " " << ans << endl;


			if (node->right)bfs.push(node->right);
			if (node->left)bfs.push(node->left);
		}
		// cout << ans << endl;
		return ans;

	}
};