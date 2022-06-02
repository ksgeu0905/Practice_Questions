class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0;
        stack<char> st;
        for(auto i : s){
            if(i=='(')
                st.push(i);
            else if (!st.empty()  && i==')')
                st.pop();
            else if (st.empty() ){
                c++;
            }
        }
        c+=st.size();
        return c;
    }
};