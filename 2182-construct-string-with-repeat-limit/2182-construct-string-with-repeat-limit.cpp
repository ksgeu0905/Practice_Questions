class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        map<char, int>m;
        for(auto it: s)
        {
            m[it]++;
        }
        priority_queue<pair<char,int>>q;
        for(auto it: m)
        {
            q.push({it.first,it.second});
        }
        string ans="";
        while(q.size()>1)
        {
            auto top1=q.top();
            q.pop();
            auto top2=q.top();
            q.pop();
            if(top1.second>=limit)
            {
                int x=limit;
                
                 if(ans.length()!=0 && ans[ans.size()-1]==top1.first)
                      x-=1;
                for(int i = 0 ; i<x;i++)
                    ans+=top1.first;
                ans+=top2.first;
                top1.second-=x;
                top2.second-=1;
                
            }
            else if(top1.second<limit)
            {
                for(int i = 0; i<top1.second;i++)
                    ans+=top1.first;
                top1.second=0;
            }
            if(top1.second!=0)
                q.push(top1);
            if(top2.second!=0)
                q.push(top2);
        }
        if(!q.empty())
        {
            auto it = q.top();
            if(it.second>=limit)
            {
                if(ans.size()!=0 && ans[ans.size()-1]==it.first)
                    limit-=1;
                for(int i=0;i<limit;i++)
                    ans+=it.first;
            }
            else
                for(int i = 0 ; i<it.second;i++)
                    ans+=it.first;
        }
        return ans;
    }
};