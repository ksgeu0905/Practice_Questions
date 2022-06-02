class Solution {
public:
    string smallestSubsequence(string s) {
         map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }
        int temp[26]={0};
        stack<char> st;
        
        for(auto i : s)
        {
            if(st.empty()|| (i>st.top()  && temp[i-97]==0)){
                st.push(i);
                temp[i-97]=1;
                mp[i]--;
            }
            else if (i< st.top()){
                if(temp[i-97]== 0){
                    while(!st.empty() && i<st.top() && mp[st.top()]>0){
                        temp[st.top()-97]=0;
                        st.pop();
                    }
                    st.push(i);
                    temp[i-97]=1;
                    mp[i]--;
                }
                else{
                    mp[i]--;
                }
            }
            else if (i== st.top()){
                mp[i]--;
            }
            
        }
        
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

