class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        int n=nums.size();
        int a=INT_MAX,b=INT_MAX;
        a=nums[0];
        for(int i=1;i<n;i++){
            if(b==INT_MAX){
                if(nums[i]>a)b=nums[i];
                else a=nums[i];
            }
            else{
                if(nums[i]>b)return true;
                else if(nums[i]>a)b=nums[i];
                else a=nums[i];
            }
        }
        return false;
        
        
    }
};