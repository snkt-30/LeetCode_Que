/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   void insertAtTail(Node* &head, Node* &tail,int val){
         Node* newNode = new Node(val);
         if(head==NULL){
             head =newNode;
             tail =newNode;
             return;
         }else{
             tail->next=newNode;
             tail=newNode;
         }
   }
    Node* copyRandomList(Node* head) {
          
            Node* CloneHead=NULL;
            Node* CloneTail=NULL;
          //1. Make a new LinkedList 
          Node* temp=head;
          while(temp){
              insertAtTail(CloneHead,CloneTail,temp->val);
              temp=temp->next;
          }

          //2.Create a map to store the randmos and all
          unordered_map<Node*,Node*>umap;
          Node* originalNode = head;
          Node* cloneNode = CloneHead;
          while(originalNode && cloneNode){
              umap[originalNode]=cloneNode;
              originalNode=originalNode->next;
              cloneNode =cloneNode->next;
          }
           
          //3.Set Pointer in CloneList
          originalNode = head;
          cloneNode = CloneHead;
          while(originalNode && cloneNode){
              cloneNode->random = umap[originalNode->random];
              originalNode = originalNode->next;
              cloneNode =cloneNode->next;
          }
          return CloneHead;
    }
};