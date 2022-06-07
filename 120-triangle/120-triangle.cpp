class Solution {
public:
    int fun(vector<vector<int>>& tri,int j,int i,vector<vector<int>> &dp){
        if(j>tri.size()-1 || i > j)
            return 40000000;
        if(j==tri.size()-1)
            return tri[j][i];
        if(dp[j][i]!=INT_MAX)
            return dp[j][i];
        int down=tri[j][i]+fun(tri,j+1,i,dp);
        int dia=tri[j][i]+fun(tri,j+1,i+1,dp);
        return dp[j][i]=min(down,dia);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return fun(triangle,0,0,dp);   
    }
};