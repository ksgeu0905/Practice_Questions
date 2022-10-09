class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>l(nums.size()),r(nums.size());
        l[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            l[i]=l[i-1]+nums[i];
        }
        int n=nums.size();
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(l[i]==r[i])return i;
        }
        return -1;
    }
};