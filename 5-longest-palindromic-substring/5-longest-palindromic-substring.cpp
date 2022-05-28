class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        int maxi=1;
        string ans="";
        ans+=s[0];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)
                    dp[i][j]=true;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(j-i==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true){
                        dp[i][j]=true;
                    }
                }
                
                if(dp[i][j] && j-i+1>maxi){
                    maxi=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};