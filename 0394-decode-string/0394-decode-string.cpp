class Solution {
public:
    string decodeString(string s1){
        stack<string> s;
        vector<int> v;
        string str="";
        for(auto i : s1){
            if(i>='0' && i<='9'){
                str+=i;
            }
            else if(i== '['){
                v.push_back(stoi(str));
                str.clear();
                string temp="";
                temp+=i;
                s.push(temp);
                temp.clear();
            }
            else if (i>='a' && i<='z'){
                string temp="";
                temp+=i;
                s.push(temp);
                temp.clear();
            }
            else if (i==']'){
                string str2="";
                while(!s.empty() && s.top()!="["){
                    str2=s.top()+str2;
                    s.pop();
                }
                s.pop();
                int t=v[v.size()-1];
                v.pop_back();
                while(t--){
                    s.push(str2);
                }
            }
        }
        string ans="";
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
        
    }
};