class CombinationIterator {
public:
    vector<string> arr;
    int pos = 0;
    
    void solve(string &s, int len, int pos, string op){
        if(pos==s.size()){
            if(op.size()==len)
                arr.push_back(op);
            return;
        }
       
        solve(s,len,pos+1,op+s[pos]);
        solve(s,len,pos+1,op);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string op = "";
        solve(characters, combinationLength, 0, op);
    }
    
    string next() {
        string ans = arr[pos++];
        return ans;
    }
    
    bool hasNext() {
        return pos<arr.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */