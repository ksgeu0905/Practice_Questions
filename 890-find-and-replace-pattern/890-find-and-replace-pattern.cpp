class Solution {
public:
    bool ismatching(string word,string pat){
        map<char,char> mp;
        set<char> st;
        for(int i=0;i<pat.length();i++){
            char wc=word[i];
            char pc=pat[i];
            if(mp.find(pc)!=mp.end()){
                if(mp[pc]!=wc)
                    return false;
            }
            else{
                if(st.find(wc)!=st.end())
                    return false;
                else{
                    mp[pc]=wc;
                    st.insert(wc);
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string >ans;
        for(auto i :  words){
            if(ismatching(i,pattern))
                ans.push_back(i);
        }
        return ans;
    }
};