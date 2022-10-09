class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto a:m){
            if(a.second==1)
                return a.first;
        }
        return -1;
    }
};