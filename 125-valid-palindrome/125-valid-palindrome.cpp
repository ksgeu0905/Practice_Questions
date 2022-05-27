class Solution {
public:
    bool ispalin(string s){
        if(s=="")
            return true;
        int l=s.length();
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1])
                return false;
        }
        return true;
    }
    bool isPalindrome(string str) {
        string s="";
        for(auto i :str){
            if(i>='A' && i<='Z')
                s+=(i+32);
            if(i>='a' && i<='z')
                s+=i;
            if(i>='0' && i<='9')
                s+=i;
        }
        return ispalin(s);
    }
};