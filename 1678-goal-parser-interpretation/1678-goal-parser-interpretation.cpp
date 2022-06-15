class Solution {
public:
    string interpret(string str) {
        string ans="";
        int i=0;
        int n=str.length();
        while(i<n){
            if(str[i]=='G'){
                ans+='G';
                i++;
            }
            else if (str[i]=='('){
                if(str[i+1]==')'){
                    ans+='o';
                    i+=2;
                }
                else{
                    ans+="al";
                    i+=4;
                }
            }
        }
        return ans;
    }
};