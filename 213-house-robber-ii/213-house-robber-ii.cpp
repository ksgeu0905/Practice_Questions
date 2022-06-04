class Solution {
public:
    int fun(vector<int> &nums){
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            int n_pick=0+dp[i-1];
            dp[i]=max(pick,n_pick);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> v1,v2;
        for(int i=0;i<nums.size()-1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            v2.push_back(nums[i]);
        }
        // int a=fun(v1);
        // int b=fun(v2);
        return max(fun(v1),fun(v2));
    }
};