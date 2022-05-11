/**
class MyHashMap {
public:
    struct Node{
        int key;
        int value;
        struct Node*next;
    }*head,*tail;
    MyHashMap() {
        head=NULL;
        tail=NULL;
    }
    
    void put(int key, int value) {
        Node *itr=head;
        if(get(key)!=-1){
            while(itr){
                if(itr->key==key){
                        itr->value=value;
                        return;
                }
                itr=itr->next;
            }
        }
        Node*p=new Node();
        p->next=NULL;
        p->key=key;
        p->value=value;
        if(head==NULL){
            head=tail=p;
        }
        else{
            tail->next=p;
            tail=p;
        }
    }
    
    int get(int key) {
        Node * itr=head;
        while(itr){
            if(itr->key==key)
                return itr->value;
            itr=itr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(!head)return;
        Node *itr=head,*prev=NULL;
        if(head->key==key){
            head=head->next;
            delete(itr);
            return;
        }
        while(itr && itr->key!=key){
            prev=itr;
            itr=itr->next;
        }
        if(itr)
             prev->next=itr->next;

        if(itr==tail){
            
            tail=prev;
        }
            delete(itr);

    }
};

 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */