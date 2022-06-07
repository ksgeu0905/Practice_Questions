class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int a1=INT_MAX,a2=INT_MAX,a3=INT_MAX;
                if(j-1 >= 0)
                    a1=matrix[i][j]+dp[i-1][j-1];
                a2=matrix[i][j]+dp[i-1][j];
                if(j+1 < n)
                    a3=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(a1,min(a2,a3));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};