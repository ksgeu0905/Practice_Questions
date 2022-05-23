class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto i : stones)
            q.push(i);
        while(q.size()>1){
            int y=q.top();q.pop();
            int x=q.top();q.pop();
            if(y>x)
                q.push(y-x);
        }
        if(q.size()==1)return q.top();
        return 0;
    }
};