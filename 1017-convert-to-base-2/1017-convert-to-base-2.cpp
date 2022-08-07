class Solution {
public:
    string baseNeg2(int n) {
        if(n==0)
            return "0";
        int x=n;
        int rem=0;
        string s="";
        while(x!=1){
            if(x%2==0){
                s='0'+s;
            }
            else{
                s='1'+s;
            }
            if(x>0)
                x=(-1)*x/2;
            else
                x=((-1)*x+1)/2;
        }
        s='1'+s;
        return s;
    }
};