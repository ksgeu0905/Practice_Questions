class compare{
    public:
    bool operator()(pair<int,string> a,pair<int,string>b){
        if(a.first<b.first)
            return true;
        if(a.first==b.first)
            return a.second>b.second;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       map<string,int> m;
        vector<string>ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>q;
        for(auto i : words){
            m[i]++;
        }
        
        for(auto i:m){
            q.push({i.second,i.first});
        }
    
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
        
    }
};