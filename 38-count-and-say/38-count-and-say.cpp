class Solution {
public:
    string countAndSay(int n) {
        string str="11";
        if(n==1)
            return "1";
        if(n==2){
            return "11";
        }
        string str2;
        int l,c;
        for(int j=3;j<=n;j++){
            str2="";
            l=str.length(),c=0;
            int i=0;
            for(i=0;i<l-1;i++){
                if(str[i]!=str[i+1]){
                    c++;
                    str2+=to_string(c)+str[i];
                    c=0;
                }
                else{
                    c++;
                }
            }
            str2+=to_string(c+1)+str[i];
            str=str2;
        }
        return str;
        
    }
};