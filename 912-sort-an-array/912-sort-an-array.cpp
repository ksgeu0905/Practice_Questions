class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto i:nums){
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};