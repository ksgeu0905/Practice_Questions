class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int min=0,max=0;
        for(int i=0;i<nums.size();i++){
            min=nums[i];
            max=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<min)
                    min=nums[j];
                if(nums[j]>max)
                    max=nums[j];
                ans+=max-min;
            }
        }
        return ans;
    }
};