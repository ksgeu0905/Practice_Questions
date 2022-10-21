class Solution {
public:
    string getHint(string s, string g) {
        string ans="",g2="";
        map<char,int>mp;
        int c=0,b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==g[i]){
                b++;
            }
            else
            {
                mp[s[i]]++;
                g2+=g[i];
            }
        }
        for(int i=0;i<g2.length();i++){
            if(mp.find(g2[i])!=mp.end() && mp[g2[i]]>0){
                c++;
                mp[g2[i]]--;
            }
        }
        ans+=to_string(b);
        ans+='A'+to_string(c)+'B';
        return ans;
    }
};