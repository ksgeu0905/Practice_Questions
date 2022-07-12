class Solution {
public:
    string addBinary(string a, string b) {
        int l1=a.length(),l2=b.length();
        int i=l1-1,j=l2-1;
        int c=0;
        string ans="";
        while(i>=0 && j>=0){
            int x=a[i]-'0'+b[j]-'0'+c;
            if(x>=2){
                c=1;
                ans=to_string(x%2)+ans;
            }
            else{
                c=0;
                ans=to_string(x)+ans;
            }
            i--;j--;
        }
        while(i>=0){
            int x=a[i]-'0'+c;
            if(x>=2){
                c=1;
                ans=to_string(x%2)+ans;
            }
            else{
                c=0;
                ans=to_string(x)+ans;
            }
            i--;
        }
        while(j>=0){
             int x=b[j]-'0'+c;
            if(x>=2){
                c=1;
                ans=to_string(x%2)+ans;
            }
            else{
                c=0;
                ans=to_string(x)+ans;
            }
            j--;
        }
        if(c==1){
            ans='1'+ans;
        }
        return ans;
    }
};