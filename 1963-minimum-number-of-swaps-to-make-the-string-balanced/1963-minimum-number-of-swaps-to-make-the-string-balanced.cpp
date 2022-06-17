class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto i :s){
            if(i=='[')
                st.push(i);
            else{
                if(!st.empty() && i==']' && st.top()=='[')
                    st.pop();
                else{
                    st.push(i);
                }
            }
        }
        int x=st.size()/2;
        return (x+1)/2;
    }
};