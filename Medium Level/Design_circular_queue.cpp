/**

class MyCircularQueue {
public:
    struct Node{
        int val;
        struct Node* next;
    }*head,*tail;
    int size;
    int nodes;
    MyCircularQueue(int k) {
        head=NULL;
        tail=NULL;
        size=k;
        nodes=0;
    }
    
    bool enQueue(int value) {
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
    
    bool deQueue() {
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
    
    int Front() {
        if(nodes==0)
            return -1;
        return head->val;
    }
    
    int Rear() {
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

 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */