class Solution {
public:
    int fun(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1 >= grid[0].size() || j2<0 || j2 >= grid[0].size())return -1e8;
        if(i==grid.size()-1){
            if(j1==j2)return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                if(j1==j2){
                    maxi=max(grid[i][j1]+fun(grid,i+1,j1+x,j2+y,dp),maxi);
                }
                else{
                    maxi=max(grid[i][j1]+grid[i][j2]+fun(grid,i+1,j1+x,j2+y,dp),maxi);
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        vector<vector<vector<int>>> dp(i, vector<vector<int>>(j, vector<int>(j, -1)));
        return fun(grid,0,0,j-1,dp);
    }
};