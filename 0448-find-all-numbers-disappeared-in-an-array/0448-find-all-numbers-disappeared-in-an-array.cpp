class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=(nums[i]%n-1)%n;
            if(ind<0)ind+=n;
            nums[ind]+=n;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>=1 && nums[i]<=n)
                ans.push_back(i+1);
        }
        return ans;
    }
};