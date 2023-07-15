//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int n)
    {
        // code here.. 
        
        int mid=ceil(n+1)/2;
        
        if(n&1)
        {
            mid--;
        }
        
        stack<int> backup;
        
        while(!st.empty() and mid)
        {
            int val=st.top();
            
            backup.push(val);
            st.pop();
            mid--;
        }
        
        st.pop();
        
        while(!backup.empty())
        {
            int val=backup.top();
            backup.pop();
            
            st.push(val);
        }
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends