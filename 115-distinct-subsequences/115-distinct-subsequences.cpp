class Solution {
public:
    int find(string &s,string &t,int i, int j,vector<vector<int>> & dp){
        if(j==t.length())
            return 1;
        if(i==s.length())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int x=0,y=0;
        if(s[i]==t[j]){
            x=find(s,t,i+1,j+1,dp);
        }
        y=find(s,t,i+1,j,dp);
        return dp[i][j]=x+y;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return find(s,t,0,0,dp);   
    }
};