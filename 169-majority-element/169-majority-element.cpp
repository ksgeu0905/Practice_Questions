class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto i: nums){
            m[i]++;
        }
        for(auto a:m){
            if(a.second>nums.size()/2)
                return a.first;
        }
        return -1;
    }
};