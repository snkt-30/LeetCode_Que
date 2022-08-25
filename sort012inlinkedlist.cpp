#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node* segregate(Node *head) {
        
        // Add code here
        Node *ptr=head;
        int i=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            i++;
        }
        int arr[i+1];
        ptr=head;
        for(int j=0; j<i; j++){
            arr[j]=ptr->data;
            ptr=ptr->next;
        }
        sort(arr, arr+i);
        ptr=head;
        for(int j=0; j<i; j++){
            ptr->data=arr[j];
            ptr=ptr->next;
        }
        return head;
        
    }
int main()
{
}