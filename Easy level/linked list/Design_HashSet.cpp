/**
class MyHashSet {
public:
    struct Node{
        int val;
        Node * next;
    }*head,*tail;
    MyHashSet() {
        tail=NULL;
        head=NULL;
    }
    
    void add(int key) {
        if(contains(key)==true)
            return;
        Node*p=new Node();
        p->next=NULL;
        p->val=key;
        if(head==NULL){
            head=tail=p;
        }
        else{
            tail->next=p;
            tail=p;
        }
    }
    
    void remove(int key) {
        Node *itr=head,*prev=NULL;
        if(!head)
            return;
        if(head->val==key){
            head=head->next;
            delete(itr);
            return;
        }
        while(itr && itr->val!=key){
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
    
    bool contains(int key) {
        Node*itr=head;
        while(itr){
            if(itr->val==key)
                return true;
            itr=itr->next;
        }
        return false;
    }
};

 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */