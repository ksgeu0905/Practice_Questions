class Solution {
public:
    string removeOuterParentheses(string str) {
        stack<char> s;
        string ans="";
        for(auto i :str){
            if(i=='('){
                s.push('(');
                if(s.size()>1)
                    ans+=i;
            }
            else{
                s.pop();
                if(s.size()>=1)
                    ans+=i;
            }      
        }
        return ans;
    }
};