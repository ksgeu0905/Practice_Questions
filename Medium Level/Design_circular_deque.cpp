/**

class MyCircularDeque {
public:
     struct Node{
        int val;
        struct Node* next;
    }*head,*tail;
    int size;
    int nodes;
    MyCircularDeque(int k) {
        head=NULL;
        tail=NULL;
        size=k;
        nodes=0;
    }
    
    bool insertFront(int value) {
        if(nodes==size)
            return false;
        Node *p=new Node;
        p->val=value;
        p->next=NULL;
        if(head==NULL){
            head=tail=p;
            p->next=head;
        }
        else{
            p->next=head;
            head=p;
            tail->next=head;
        }
        nodes++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(nodes==size)
            return false;
        Node *p=new Node;
        p->val=value;
        p->next=NULL;
        if(head==NULL){
            head=tail=p;
            p->next=head;
        }
        else{
            p->next=head;
            tail->next=p;
            tail=p;
        }
        nodes++;
        return true;
    }
    
    bool deleteFront() {
        if(nodes==0)
            return false;
        Node*ptr=NULL;
        ptr=head;
        if(nodes==1){
            head=tail=NULL;
        }
        else{
            tail->next=head->next;
            head=head->next;
        }
        delete(ptr);
        nodes--;
        return true;
    }
    
    bool deleteLast() {
        if(nodes==0)
            return false;
        Node *ptr=NULL,*itr=head;
        ptr=tail;
        if(nodes==1){
            head=tail=NULL;
        }
        else{
            while(itr->next!=tail)
                itr=itr->next;
            tail=itr;
            tail->next=head;
        }
        delete(ptr);
        nodes--;
        return true;
    }
    
    int getFront() {
         if(nodes==0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(nodes==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(nodes==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(nodes==size)
            return true;
        return false;
    }
};

 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */