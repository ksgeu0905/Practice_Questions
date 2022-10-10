class Solution {
public:
    string breakPalindrome(string p) {
        int l=p.length();
        if(l==1)return "";
        if(l%2==0){
            for(int i=0;i<=l/2;i++){
                if(p[i]>'a'){
                    p[i]='a';
                    return p;
                }
            }
            p[l-1]++;
            return p;
        }
        for(int i=0;i<l/2;i++){
            if(p[i]>'a'){
                 p[i]='a';
                 return p;
            }
        }
        p[l-1]++;
        return p;
    }
};