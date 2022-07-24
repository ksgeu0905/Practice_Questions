class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1),hash(n,-1);
        int maxi=1,last_ind=0;
        for(int cur=0;cur<n;cur++){
            for(int prev=0;prev<cur;prev++){
                if(nums[cur]%nums[prev]==0 && dp[cur] < 1 + dp[prev]){
                    dp[cur]=1+dp[prev];
                    hash[cur]=prev;
                }
            }
            if(dp[cur]>maxi){
                maxi=dp[cur];
                last_ind=cur;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_ind]);
        while(hash[last_ind] !=-1){
            last_ind=hash[last_ind];
            ans.push_back(nums[last_ind]);
        }
        return ans;
        
    }
};