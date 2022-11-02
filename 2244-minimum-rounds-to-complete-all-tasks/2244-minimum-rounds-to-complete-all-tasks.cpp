class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(auto i :tasks){
            mp[i]++;
        }
        int r=0;
        for(auto i : mp){
            if(i.second==1)return -1;
            int x = i.second;
            r+=(x+2)/3;
        
        }
        return r;
    }
};