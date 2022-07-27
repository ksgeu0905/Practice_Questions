class Solution {
public:
    int find(vector<int>&arr,int i,int &k,int n,vector<int>&dp){
        if(i==n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int len=0,max_ele=INT_MIN,maxi=INT_MIN;
        for(int ind=i; ind< min(n,i+k) ; ind++){
            len++;
            max_ele=max(max_ele,arr[ind]);
            int sum = max_ele * len + find(arr,ind+1,k,n,dp);
            maxi=max(maxi,sum);
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return find(arr,0,k,arr.size(),dp);
    }
};