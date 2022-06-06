class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> v,v2;
        string str="";
        for(int i=0 ; i< s.length();i++){
            if(s[i]>='0' && s[i]<='9' && (s[i+1]=='\0' || s[i+1]==' ')){
                v.push_back(s[i]-'0');
            }
            else if(s[i]>='0' && s[i]<='9' && (s[i+1]>='0' && s[i+1]<='9')){
                v.push_back((s[i]-'0')*10 + s[i+1]-'0');
                i++;
            }
        }
        v2=v;
        sort(v2.begin() ,v2.end());
        for(int i=0;i<v.size()-1;i++){
            if(v2[i]==v2[i+1])return false;
        }
        return v2==v;
    }
};