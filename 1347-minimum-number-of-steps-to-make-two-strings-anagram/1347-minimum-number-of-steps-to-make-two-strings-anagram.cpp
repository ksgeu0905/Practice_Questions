class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1,mp2;
        int c=0;
        for(auto i : s){
            mp1[i]++;
        }
        for(auto i : t){
            mp2[i]++;
        }
        for(auto i : mp1){
            if(i.second > mp2[i.first]){
                c+=i.second-mp2[i.first];
            }
        }
        return c;
    }
};