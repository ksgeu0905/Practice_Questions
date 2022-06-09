class Solution {
public:
    string reverseStr(string s, int k) {
        int temp=k,i=0,f=0;
        string ans="",str="";
        while(i<s.length()){
            for(int j=0;j<k;j++){
                str=s[i]+str;
                i++;
                if(i>=s.length()){
                    f=1;
                    break;
                }
            }
            ans+=str;
            str.clear();
            if(f==1) return ans;
            for(int j=0;j<k;j++){
                ans+=s[i];
                i++;
                if(i>=s.length()){
                    f=1;
                    break;
                }
            }
            if(f==1) return ans;            
        }
        return ans;
    }
};