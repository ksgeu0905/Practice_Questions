class Solution {
public:
    int find(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.length()||j>=s2.length())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int c=0,y=0,z=0;
        if(s1[i]==s2[j])
            c=1+find(s1,s2,i+1,j+1,dp);
        else{
            y=find(s1,s2,i+1,j,dp);
            z=find(s1,s2,i,j+1,dp);
        }
        return dp[i][j]=c+max(y,z);
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        string s2=s;
        reverse(s2.begin(),s2.end());
        return find(s,s2,0,0,dp);
    }
};