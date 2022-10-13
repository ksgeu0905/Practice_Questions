class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        if(n==1)return 1;
        map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        int ans=0,f=0;
        for(auto i :mp){
            if(i.second%2==0)ans+=i.second;
            else {
                ans+=(i.second-1);
                f=1;
            }
        }
        if(f==1)
            return ans+1;
        return ans;
    }
};