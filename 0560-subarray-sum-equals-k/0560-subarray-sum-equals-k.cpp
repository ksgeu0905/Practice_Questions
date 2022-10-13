class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int c=0;
       unordered_map<int,int>mp;
        mp[0]=1;
        int s=0;
        for(auto i : nums){
            s+=i;
            if(mp.find(s-k)!=mp.end())c+=mp[s-k];
            mp[s]++;
        }
        return c;
    }
};