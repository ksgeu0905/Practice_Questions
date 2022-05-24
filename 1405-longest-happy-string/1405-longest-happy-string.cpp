class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        if(a)q.push({a,'a'});
        if(b)q.push({b,'b'});
        if(c)q.push({c,'c'});
        string s="";
        while(q.size()>1){
            pair<int,char> x=q.top();
            q.pop();
            pair<int,char> y=q.top();
            q.pop();
            if(x.first>=2){
                s+=x.second;
                s+=x.second;
                x.first-=2;
            }
            else{
                s+=x.second;
                x.first-=1;
            }
            
            if(y.first>=2 && y.first > x.first){
                s+=y.second;
                s+=y.second;
                y.first-=2;
            }
            else{
                s+=y.second;
                y.first-=1;
            }          
            
            if(x.first)q.push(x);
            if(y.first)q.push(y);
        }
        if(q.empty())return s;
        if(q.top().first>=2){
            s+=q.top().second;
            s+=q.top().second;
        }
        else{
            s+=q.top().second;
        }
        return s;
    }
};