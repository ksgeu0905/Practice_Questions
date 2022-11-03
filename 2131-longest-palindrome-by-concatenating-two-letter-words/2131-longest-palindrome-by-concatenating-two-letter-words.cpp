class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int ans=0;
        mp[words[0]]++;
        for(int i=1;i<words.size();i++){
            string rev ="";
            rev+= words[i][1];
            rev+= words[i][0];
            if(mp.find(rev)!=mp.end() && mp[rev]>0){
                ans+=4;
                mp[rev]--;
            }
            else{
                mp[words[i]]++;
            }
        }
        for(auto i: mp){
            string s = i.first;
            if(s[0]==s[1] && mp[s]>0){
                return ans+2;
            }
        }
        return ans;
        return 0;
    }
};