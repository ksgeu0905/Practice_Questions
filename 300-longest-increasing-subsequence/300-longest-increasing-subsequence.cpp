class Solution {
public:
    int find(int i,int last,vector<int>&nums,vector<vector<int>>&dp,int &n){
        if(i==n)return 0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        int p=INT_MIN;
        int np=find(i+1,last,nums,dp,n);
        if(last==-1 || nums[i] > nums[last]){
            p=1+find(i+1,i,nums,dp,n);
        }
        return dp[i][last+1]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(0,-1,nums,dp,n);
    }
};