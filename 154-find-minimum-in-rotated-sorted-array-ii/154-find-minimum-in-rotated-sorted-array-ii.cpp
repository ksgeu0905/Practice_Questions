class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,min;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
             if(s==e)return nums[mid];

            if(nums[mid]>nums[e])
                s=mid+1;
            else if(nums[mid]<nums[e])
                e=mid;
            else
                e--;
            
        }
        return -1;
    }
};