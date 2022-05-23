class compare1{
    public:
        bool operator() (pair<int,int>a,pair<int,int>b){
            return a.first>b.first;
        }
};
class compare2{
    public:
        bool operator() (pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        }
};
class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare1> q;
        for(int i=0;i<nums.size();i++){
            q.push(make_pair(nums[i],i));
        }
        while(q.size()>k)q.pop();
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare2> q2;
        while(!q.empty()){
            q2.push(q.top());
            q.pop();
        }
        vector<int> ans;
        while(!q2.empty()){
            ans.push_back(q2.top().first);
            q2.pop();
        }
        
        return ans;
    }
};