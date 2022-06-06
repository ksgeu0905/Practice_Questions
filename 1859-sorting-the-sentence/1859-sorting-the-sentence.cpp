class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>> v;
        string str="";
        for(auto i : s){
            if(i>='0' && i<='9'){
                v.push_back({i-'0',str});
                str.clear();
            }
            if((i>='a' && i<='z') || (i>='A' && i<='Z'))
                str+=i;
        }
        sort(v.begin(),v.end());
        string ans="";
        for(auto i : v){
            ans+=i.second;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
    }
};