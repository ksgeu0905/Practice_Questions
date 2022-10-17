class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>st;
        for(auto i :sentence)st.insert(i);
        if(st.size()==26)return true;
        return false;
    }
};