
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto i : arr){
            m[i]++;
        }
        priority_queue<int> q;
        for(auto i : m){
            q.push(i.second);
        }
        int n=arr.size();
        int h=n/2;
        int c=0;
        while(n>h){
            n=n-q.top();
            c++;
            q.pop();
        }
        return c;
    }
};