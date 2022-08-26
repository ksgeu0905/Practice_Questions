class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int c=s.length();
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(j-i==1){
                    if(s[i]==s[j])
                        dp[i][j]=1;
                }
                else{
                    if(dp[i+1][j-1] && s[i]==s[j])
                        dp[i][j]=1;
                }
                if(dp[i][j])c++;
            }
        }
        return c;     
    }
};