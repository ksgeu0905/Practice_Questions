class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans;
        ans=binary(nums,target,0,nums.size()-1);
        return ans;
    }
    int binary(vector<int>nums,int key,int s,int e){
        if(s>e)
            return -1;
        int mid=s+(e-s)/2;
        if(nums[mid]==key)
            return mid;
        if(nums[mid]<key)
            return binary(nums,key,mid+1,e);
        else
            return binary(nums,key,s,mid-1);          
    }
};