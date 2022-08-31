class Solution {
public:
    int find(int i,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i>=arr.size())return 0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        int np=find(i+1,last,arr,dp);
        int p=0;
        if(last==-1 || arr[i][0]>arr[last][1])
            p=1+find(i+1,i,arr,dp);
        return dp[i][last+1]=max(np,p);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(0,-1,pairs,dp);
    }
};