class Solution {
public:
    int find(int m,int n,vector<vector<int>> & dp, vector<vector<int>> ogrid){
        
        if(m==0 && n==0 && ogrid[m][n]!=1)
            return 1;
        if(m<0 || n<0)
            return 0;
        if(ogrid[m][n]==1)
            return 0;
        if(dp[m][n]!= -1 )return dp[m][n];
        int up=find(m-1,n,dp,ogrid);
        int left=find(m,n-1,dp,ogrid);
        
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ogrid) {
        int m=ogrid.size();
        int n=ogrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(m-1,n-1,dp,ogrid);
    }
};