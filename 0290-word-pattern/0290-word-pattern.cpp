class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string>mp1;
        map<string,char>mp2;
        vector<string>s2;
        string str="";
        for(auto i:s){
            if(i==' '){
                s2.push_back(str);
                str="";
            }
            else
                str+=i;
        }
        s2.push_back(str);
        if(p.size()!=s2.size())return false;
        for(int i=0;i<p.size();i++){
            if(mp1.find(p[i])!=mp1.end() && mp1[p[i]]!=s2[i])return false;
            mp1[p[i]]=s2[i];
        }
        for(int i=0;i<p.size();i++){
            if(mp2.find(s2[i])!=mp2.end() && mp2[s2[i]]!=p[i])return false;
            mp2[s2[i]]=p[i];
        }
        return true;
    }
};