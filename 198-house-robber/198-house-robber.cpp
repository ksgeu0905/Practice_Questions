class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0], prev2=0,curr=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i]+prev2;
            int n_pick=prev;
            curr=max(pick,n_pick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};