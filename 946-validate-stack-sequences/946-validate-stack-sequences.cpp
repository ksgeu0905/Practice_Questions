class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>pu,po;
        for(int i=popped.size()-1 ;i>=0;i--){
            po.push(popped[i]);
        }        
        
        for(auto i : pushed){
            pu.push(i);
            while(!pu.empty() && !po.empty() && pu.top()==po.top()){
                pu.pop();
                po.pop();
            }
        }
        if(!pu.empty() || !po.empty())
            return false;
        return true;
    }
};