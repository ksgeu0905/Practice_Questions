class FrontMiddleBackQueue {
public:
    list<int>first,second;
    int s1=0,s2=0;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        if(s1==0 && s2==0){
            second.push_front(val);
            s2++;
        }
        else if(s1<s2){
            first.push_front(val);
            s1++;
        }
        else{
            second.push_front(first.back());
            first.pop_back();
            first.push_front(val);
            s2++;
        }
    }
    
    void pushMiddle(int val) {
        if(s1<s2){
            first.push_back(val);
            s1++;
        }
        else if(s1==s2){
            second.push_front(val);
            s2++;
        }
    }
    
    void pushBack(int val) {
        if(s1<s2){
            first.push_back(second.front());
            second.pop_front();
            second.push_back(val);
            s1++;
        }
        else if(s1==s2){
            second.push_back(val);
            s2++;

        }
        
    }
    
    int popFront() {
        if(s1==0 && s2==0)
            return -1;
        else if(s1==0 && s2==1){
            int x=second.front();
            second.pop_front();
            s2--;
            return x;
        }
        int x=first.front();
        if(s1<s2){
            first.push_back(second.front());
            second.pop_front();
            s2--;
            first.pop_front();
        }
        else{
            first.pop_front();
            s1--;
        }
        return x;
    }
    
    int popMiddle() {
        if(s1==0 && s2==0)
            return -1;
        int x;
        if(s1<s2){
            x=second.front();
            second.pop_front();
            s2--;
        }
        else{
            x=first.back();
            first.pop_back();
            s1--;
        }
        return x;
    }
    
    int popBack() {
        if(s1==0 && s2==0)
            return -1;
        int x;
        if(s1<s2){
            x=second.back();
            second.pop_back();
            s2--;
        }
        else{
            x=second.back();
            second.push_front(first.back());
            first.pop_back();
            s1--;
            second.pop_back();
        }
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */