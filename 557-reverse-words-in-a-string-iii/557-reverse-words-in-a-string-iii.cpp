class Solution {
public:
    string reverseWords(string s) {
        string str="",ans="";
        for(auto i : s){
            if(i==' '){
                ans+=str+" ";
                str.clear();
            }
            else{
                str=i+str;
            }
        }
        ans+=str;
        return ans;
    }
};