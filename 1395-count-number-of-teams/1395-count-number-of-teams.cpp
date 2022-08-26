class Solution {
public:
    int func(vector<int>&rating, int i, int c, int l,vector<vector<vector<int>>>&dp)
    {
        if(c==3) return 1;
        if(i==rating.size()) return 0;
        if(dp[c][i][l+1]!=-1) return dp[c][i][l+1];
        int np=func(rating, i+1,c,l,dp);
        int y=0;
        if(l==-1||rating[l]<rating[i])
             y=func(rating, i+1,c+1,i,dp);
        return dp[c][i][l+1]=np+y;
    }
    int funcdec(vector<int>&rating, int i, int c, int l,vector<vector<vector<int>>>&dp)
    {
        if(c==3) return 1;
        if(i==rating.size()) return 0;
        if(dp[c][i][l+1]!=-1) return dp[c][i][l+1];

        int np=funcdec(rating, i+1,c,l,dp);
        int y=0;
        if(l==-1||rating[l]>rating[i])
             y=funcdec(rating, i+1,c+1,i,dp);
        return dp[c][i][l+1]=np+y;

    }
    int numTeams(vector<int>& rating) {
        int n=rating.size();
      vector<vector<vector<int>>>dp(4,vector<vector<int>>(n,vector<int>(n+1,-1)));
      vector<vector<vector<int>>>dp2(4,vector<vector<int>>(n,vector<int>(n+1,-1)));
      int x=func(rating,0,0,-1,dp);  
      int y=funcdec(rating,0,0,-1,dp2);
        return x+y;
    }
    
};