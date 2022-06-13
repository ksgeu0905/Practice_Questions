class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        int d,c;
        for(int i=0;i<queries.size();i++){
            c=0;
            for(int j=0;j<points.size();j++){
                d=pow((queries[i][0]-points[j][0]),2)+pow((queries[i][1]-points[j][1]),2);
                if(d<=pow(queries[i][2],2))
                    c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};