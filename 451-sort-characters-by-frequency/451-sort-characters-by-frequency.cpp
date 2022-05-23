class Solution {
public:
    string frequencySort(string s) {
        map<int,int> m;
        for(auto i :s)
            m[i]++;
        priority_queue<pair<int,int>>q;
        for(auto i :m){
            q.push({i.second,i.first});
        }
        string ans="";
        while(!q.empty()){
            int x=q.top().first;
            while(x--){
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
    }
};