class Solution {
public:
    bool find(int i,int j,int turn,int s1,int s2,vector<int>&arr,vector<vector<vector<int>>>&dp){
        if(i>j){
            if(s1>s2)return true;
            return false;
        }
        if(dp[i][j][turn]!=-1)return dp[i][j][turn];
        if(turn){
            s1+=max(arr[i],arr[j]);
        }
        else{
            s2+=max(arr[i],arr[j]);
        }
        return dp[i][j][turn]=(find(i+1,j,!turn,s1,s2,arr,dp) || find(i,j-1,!turn,s1,s2,arr,dp));
        
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(piles.size(),vector<int>(2,-1)));
        return find(0,piles.size()-1,1,0,0,piles,dp);
    }
};