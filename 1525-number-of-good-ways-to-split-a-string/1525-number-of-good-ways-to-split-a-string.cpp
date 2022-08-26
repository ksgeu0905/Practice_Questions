class Solution {
public:
    int numSplits(string s) {
        map<char,int>l,r;
        for(auto i :s){
            r[i]++;
        }
        int c=0;
        for(int i=0 ; i<s.length();i++){
            l[s[i]]++;
            r[s[i]]--;
            if(r[s[i]]==0){
                r.erase(s[i]);
            }
            if(l.size()==r.size())
                c++;
        }
        return c;
        
        
    }
};