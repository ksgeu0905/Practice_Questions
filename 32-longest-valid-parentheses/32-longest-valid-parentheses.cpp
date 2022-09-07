class Solution {
public:
    int longestValidParentheses(string s) {
        int x=0,l=0,ans=0;
        for(auto i : s){
            if(i=='('){
                x++;
                l++;
            }
            else{
                x--;
                l++;
            }
            if(x==0){
               if(l>ans){
                    ans=l;
                } 
            }
            else if(x<0){
                l--;
                if(l>ans){
                    ans=l;
                }
                x=0;
                l=0;
            }
        }
        int n=s.length();
        l=0;x=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                x++;
                l++;
            }
            else{
                x--;
                l++;
            }
            if(x==0){
               if(l>ans){
                    ans=l;
                } 
            }
            else if(x<0){
                l--;
                if(l>ans){
                    ans=l;
                }
                x=0;
                l=0;
            }
        }
        return ans;
    }
};