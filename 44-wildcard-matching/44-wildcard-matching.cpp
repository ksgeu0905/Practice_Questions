class Solution {
public:
    bool find(string & s, string & t,int i ,int j,vector<vector<int>>&dp){
        if(i<0 && j<0) return 1;
        if(j < 0 ) return 0;
        if(i < 0){
            for(int ii=0 ; ii<=j; ii++){
                if(t[ii]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        int x=0,y=0;
        if(s[i]==t[j] || t[j]=='?')
            return dp[i][j]=find(s,t,i-1,j-1,dp);
        else if(t[j]=='*')
        {
             return dp[i][j]=find(s,t,i,j-1,dp) || find(s,t,i-1,j,dp);   
        }
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return find(s,t,s.length()-1,t.length()-1,dp);
    }
};