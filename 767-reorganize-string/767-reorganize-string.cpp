class Solution {
public:
    string reorganizeString(string s) {
        string res="";
        map<int,int> m;
        for(auto i :s)
            m[i]++;
        priority_queue<pair<int,int>> q;
        for(auto i:m)
            q.push({i.second,i.first});
        while(q.size()>1){
            pair<int,int> top1=q.top();
            q.pop();
            pair<int,int> top2=q.top();
            q.pop();
            res+=top1.second;
            res+=top2.second;
            
            top1.first--;
            top2.first--;
            if(top1.first>0)
                q.push(top1);
            if(top2.first>0)
                q.push(top2);
        }
        if(!q.empty()){
            if(q.top().first>1)
                return "";
            else
                res+=q.top().second;
        }
        return res;
    }
};