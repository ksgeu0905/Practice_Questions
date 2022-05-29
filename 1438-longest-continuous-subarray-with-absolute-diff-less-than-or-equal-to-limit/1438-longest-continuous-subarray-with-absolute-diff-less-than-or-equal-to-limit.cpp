class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int min_ind=0;
        int max_ind=0;
        int i=0,j=0,ans=INT_MIN;
        while(j<nums.size()){
            if(nums[j]<nums[min_ind])
                min_ind=j;
            if(nums[j]> nums[max_ind])
                max_ind=j;
            
            
            if(abs(nums[max_ind]-nums[min_ind])<=limit){
                ans=max(ans,j-i+1);
            }
            else{
                i++;
                if(i>min_ind){
                    min_ind=i;
                    for(int x=i+1;x<=j;x++){
                         if(nums[x]<nums[min_ind])
                         min_ind=x;
                    }
                }
                if(i>max_ind){
                    max_ind=i;
                     for(int x=i+1;x<=j;x++){
                         if(nums[x]>nums[max_ind])
                         max_ind=x;
                    }
                }
            }
            j++;
        }
        return ans; 
    }
};