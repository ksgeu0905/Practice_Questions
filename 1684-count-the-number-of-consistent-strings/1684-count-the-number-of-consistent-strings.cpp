class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        for(auto i :allowed){
            s.insert(i);
        }
        int ans=0,f=0;
        for(auto i : words){
            f=0;
            for(int j=0;j<i.length();j++){
                if(s.find(i[j])==s.end()){
                    f=1;
                    break;
                }
            }
            if(f==0)ans++;
        }
        return ans;
    }
};