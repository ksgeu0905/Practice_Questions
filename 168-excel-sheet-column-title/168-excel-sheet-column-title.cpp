class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num>0){
            int x=num%26;
            if(x==0){
                x=26;
            }
             char c=x+64;

            ans=c+ans;
            num=(num-x)/26;
        }
        return ans;
    }
};