class Solution {
public:
    int LCS(string &s1,string &s2,int i ,int j,vector<vector<int>> & dp){
        if(i<0 || j<0)
            return 0;
        int x=0,y=0,c=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
            c=1+LCS(s1,s2,i-1,j-1,dp);
        else{
            x=LCS(s1,s2,i-1,j,dp);
            y=LCS(s1,s2,i,j-1,dp);
        }
        return dp[i][j]=c+max(x,y);
    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=n- LCS(s1,s,n-1,n-1,dp);
        return ans;
    }
};