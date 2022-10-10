//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
struct Node* deletionBT(struct Node* root, int key);
void inn(Node *node)
{
    if(node==NULL)
        return;
    
    inn(node->left);
    cout<<node->data<<" ";
    inn(node->right);
}

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        scanf("%d ",&k);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		root=deletionBT(root,k);
		inn(root);
		cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
Structre of the node of the tree is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// you are required to complete this function
struct Node* deletionBT(struct Node* root, int key)
{
    // code here
    
    queue<Node*>bfs;
    
    
    struct Node* temp,*key_node=nullptr,*par,*node;
    
    bfs.push(root);
    
    while(!bfs.empty())
    {
         node=bfs.front();
        bfs.pop();
        
        if(node->data==key)
        {
            key_node=node;
        }
        if(node->left)
        {
            par=node;
            bfs.push(node->left);
        }
        if(node->right)
        {
            par=node;
            bfs.push(node->right);
        }
    }
    
    if(key_node!=nullptr)
    {
        key_node->data = node->data;
        if(par->right==node)
        {
            par->right=nullptr;
        }
        else
          par->left=nullptr;
          
        delete(node);
    }
    
    return root;
}

