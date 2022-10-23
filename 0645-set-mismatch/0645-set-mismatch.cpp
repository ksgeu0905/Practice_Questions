class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        int i=0;
        for(i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])
                break;
        }
        ans.push_back(nums[i]);
        int sum=accumulate(nums.begin(),nums.end(),0);
        ans.push_back(n*(n+1)/2 - sum+nums[i]);
        return ans;
        
    }
};