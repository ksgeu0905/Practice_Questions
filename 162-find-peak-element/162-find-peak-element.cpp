class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int mid;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid+1]<nums[mid])
                e=mid; 
            else
                s=mid+1;
        }
        return s;
    }
};