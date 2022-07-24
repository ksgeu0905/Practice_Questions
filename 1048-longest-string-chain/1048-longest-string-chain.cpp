class Solution {
public:
    static bool comp(string &a,string &b){
        return a.length()<b.length();
    }
    bool compare(string &s1,string &s2){
        if((s1.length()-s2.length()) !=1)return false;
        
        int i=0,j=0;
        while(i<s1.length()  && j<s2.length()){
            if(s1[i]==s2[j]){
                i++;j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.length() && j!=s2.length())return false;
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && dp[i]<1+dp[prev])
                    dp[i]=1+dp[prev];
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};