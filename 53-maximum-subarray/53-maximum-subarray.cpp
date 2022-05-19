class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=nums[0];
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            maxsum=max(sum,maxsum);
            
        }
        return maxsum;
    }
};