class Solution {
public:
    int balancedStringSplit(string s) {
        int total=0;
        int c=0;
        for(auto i : s){
            if(i=='R')
                c++;
            else
                c--;
            if(c==0)
                total++;
        }
        return total;
    }
};