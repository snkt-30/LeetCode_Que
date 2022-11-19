//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
     void bfs(vector<vector<int>>& ans, Node* node,bool flag)
     {
         queue<Node*> bfs;
         
         bfs.push(node);
         
         while(!bfs.empty())
         {
             int n=bfs.size();
             vector<int>temp;
             for(int i=0;i<n;i++)
             {
                 Node* root=bfs.front();
                 bfs.pop();
                 temp.push_back(root->data);
                 
                 if(root->left)bfs.push(root->left);
                 if(root->right)bfs.push(root->right);
                 
             }
             sort(temp.begin(),temp.end());
              ans.push_back(temp);
         }
         
     }
     
    public:
    
    bool areAnagrams(Node *root1, Node *root2)
    {
        
        if(!root1 and !root2)return true;
        
        if(!root1 or !root2)
           return false;
           
           vector<vector<int>> l;
           vector<vector<int>> r;
           
           
           bfs(l,root1,0);
           bfs(r,root2,1);
           
          int l_size=l.size();
          int r_size=r.size();
          
          if(l_size!=r_size)return false;
          
          for(int i=0;i<l_size;i++)
          {
              auto x1=l[i];
              auto x2=r[i];
              
              if(x1!=x2)return false;
          }
           
           return true;
           
           
           
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends