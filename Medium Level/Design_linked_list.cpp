class MyLinkedList {
public:
    struct node{
        int val;
        struct node *next;
    }*head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)return -1;
        node*ptr=head;
        while(index--)
            ptr=ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        node*ptr=new node();
        ptr->val=val;
        ptr->next=NULL;
        size++;
        if(head==NULL){
            head=ptr;return;
        }
        ptr->next=head;
        head=ptr;
            
    }
    
    void addAtTail(int val) {
        node*ptr=new node;
        ptr->val=val;
        ptr->next=NULL;
        node*itr=head;
        size++;
        if(head==NULL){
            head=ptr;return;
        }
        while(itr->next)
            itr=itr->next;
        itr->next=ptr;
        return;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size)return ;
        node*itr=head;
        node*ptr=new node();
        ptr->val=val;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
        int i=0;
        while(i!=index-1){
            itr=itr->next;
            i++;
        }
        ptr->next=itr->next;
        itr->next=ptr;
        size++;

    }
    
    void deleteAtIndex(int index) {
         if(index<0 || index>=size)return ;
         if(index==0){
                node *t=head;
                head=head->next;
                size--;
                delete(t);
                return;
         }
        node*itr=head;
        int i=0;
        while(i!=index-1){
            itr=itr->next;
            i++;
        }
        size--;
        node *t=itr->next;
        itr->next=itr->next->next;
        delete(t);
        

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */