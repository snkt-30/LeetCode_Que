//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
Node* find_node(Node* root, int tar)
{
    if(!root)return nullptr;
    
    if(root->data==tar)
       return root;
    else if(root->data>tar)
    {
        return find_node(root->left,tar);
    }
    else 
      return find_node(root->right,tar);
      
     return root;
}


class Solution{
public:
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        
        if(!root)return -1;
        map<int,vector<int>>mp;
        
        queue<pair<Node*,int>> bfs;
        
        Node* node=find_node(root,target);
        
        if(node==nullptr)
         return -1;
        
        int axis=INT_MAX;
        int nd=0;
        
        bfs.push(make_pair(node,0));
        
        while(!bfs.empty())
        {
            auto x=bfs.front();
            bfs.pop();
            
            Node* v=x.first;
            int ax=x.second;
            
            mp[ax].push_back(v->data);
            
            if(v->data==target)
            {
                axis=ax;
            }
            
            if(v->left)
              bfs.push(make_pair(v->left,ax-1));
              
             if(v->right)
                bfs.push(make_pair(v->right,ax+1));
        }
        
        if(axis==INT_MAX)
          return -1;
          
          
        int n=mp[axis].size();
        
        int sum=0;
        
        for(int i=n-1;i>=0 ;i--)
        {
            if(mp[axis][i]==target)
              break;
              
              sum+=mp[axis][i];
        }
        
        return sum;
        
        
        
    }
};

//{ Driver Code Starts.

// Function to Build Tree
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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends