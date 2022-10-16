class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto i :strs){
            string s = i;
            sort(i.begin(),i.end());
            mp[i].push_back(s);
        }
        for(auto i :mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};