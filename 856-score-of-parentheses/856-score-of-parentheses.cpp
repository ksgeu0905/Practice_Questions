class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        for(auto i : str){
            if(i=='(')
                s.push(-1);
            else{
                if(s.top()==-1)
                {
                    s.pop();
                    s.push(1);
                }
                else{
                    int a=0;
                    while(s.top()!=-1)
                    {
                        a+=s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(a*2);
                }
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};