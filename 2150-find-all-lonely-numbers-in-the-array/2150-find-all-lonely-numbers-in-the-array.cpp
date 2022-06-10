class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        vector<int> ans;
        for(auto i : nums){
            if(mp[i]==1 && mp[i-1]==0 && mp[i+1]==0)
                ans.push_back(i);
        }
        return ans;
    }
};