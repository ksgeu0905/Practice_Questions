class CustomStack {
public:
    stack<int> st;
    int maxsize=0;
    CustomStack(int maxSize) {
        maxsize=maxSize;
    }
    
    void push(int x) {
        if(st.size()<maxsize){
            st.push(x);
        }
    }
    
    int pop() {
        int x=-1;
        if(!st.empty()){
            x=st.top();
            st.pop();
        }
        return x;
    }
    
    void increment(int k, int val) {
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        int x=v.size();
        if(k>x){
            k=x;
        }
        while(k--){
            v[x-1]+=val;
            x--;
        }
        for(int i=v.size()-1;i>=0;i--){
            st.push(v[i]);   
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */