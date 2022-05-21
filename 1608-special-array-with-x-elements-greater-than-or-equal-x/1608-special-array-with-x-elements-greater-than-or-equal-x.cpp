class Solution {
public:
    int count(vector<int> nums,int x){
        int l=0,e=nums.size()-1,mid=0,ans=-1;
        if(x>nums[e])return -1;
        while(l<=e){
            mid=l+(e-l)/2;
            if(nums[mid]==x){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid ]<x)
                l=mid+1;
            else{
                e=mid-1;
                ans=mid;
            }
        }
        
            return ans;
        
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            for(int x=0;x<=nums.size();x++){
                if(x==nums.size()-count(nums,x))
                    return x;
            }
            return -1;
        
    }
};