class Solution {
public:
    bool find(string &s1, string &s2, string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i==s1.length() && j==s2.length() && k==s3.length())return true;
      
        if(dp[i][j]!=-1)return dp[i][j];
        bool x=false,y=false,z=false;
        
        if(s1[i]==s3[k] && s2[j]==s3[k])
            x=find(s1,s2,s3,i+1,j,k+1,dp)|find(s1,s2,s3,i,j+1,k+1,dp);
        else if(s1[i]==s3[k])
            y=find(s1,s2,s3,i+1,j,k+1,dp);
        else if(s2[j]==s3[k])
            z=find(s1,s2,s3,i,j+1,k+1,dp);
        else 
            return false;
        return dp[i][j]=x|y|z;
        

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1+n2 != n3)return false;
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return find(s1,s2,s3,0,0,0,dp);
    }
};