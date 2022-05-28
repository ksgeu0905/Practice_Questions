class Solution {
public:
   class compare{
        public:
        bool operator()(pair<pair<int,int>,int> a ,pair<pair<int,int>,int> b){
            if(a.first.first>b.first.first)
                return true;
            if(a.first.first==b.first.first){
                if(a.first.first%2==0 && a.first.second>b.first.second)
                        return true;
                else if(a.first.first%2==0 && a.first.second<b.first.second)
                        return false;
                else if(a.first.second<b.first.second)
                        return true;
                else
                    return false;
            }
            return false;
        }
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare> pq;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                pq.push({{i+j,j},nums[i][j]});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};