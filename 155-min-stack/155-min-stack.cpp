class MinStack {
public:
    multiset<int>s;
    vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        s.insert(val);
        v.push_back(val);
    }
    
    void pop() {
        s.erase(s.find(v[v.size()-1]));
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return *(s.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */