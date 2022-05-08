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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* ptr=head,*front=NULL;
        
        
        // Insert copy nodes for each node 
        while(ptr){
            front=ptr->next;
            Node*copy=new Node(ptr->val);
            ptr->next=copy;
            copy->next=front;
            ptr=front;
        }
        
        // assign random nodes for copied nodes
        ptr=head;
        while(ptr){
            if(ptr->random){
                ptr->next->random=ptr->random->next;
            }
            ptr=ptr->next->next;
        }
        
        // Separate copy and original nodes
        ptr=head;
        Node*dummy=new Node(0);
        dummy->next=ptr->next;
        Node*ptr2=dummy;
        while(ptr){
            front=ptr->next->next;
            ptr2->next=ptr->next;
            ptr->next=front;
            ptr2=ptr2->next;
            ptr=ptr->next;            
        }
        return dummy->next;
        
    }
};
*/