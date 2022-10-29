class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int ,int>>> q;
        for(int i=0;i<points.size();i++){
            int d=(points[i][0]*points[i][0]) +(points[i][1]*points[i][1]);
            q.push({d,i});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};