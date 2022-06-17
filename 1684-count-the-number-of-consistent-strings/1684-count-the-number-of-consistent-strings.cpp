class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         int res = words.size();
        bool hash[26] = {false};
        
        for (char c: allowed) 
            hash[c - 'a'] = true;
        
        for (string word: words) {
            for (char c: word){
                if (hash[c - 'a']==false) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};