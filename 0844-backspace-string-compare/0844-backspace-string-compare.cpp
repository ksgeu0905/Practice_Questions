class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>a1,a2;
        for(auto i : s){
            if(i=='#' && a1.size()>0){
                a1.pop_back();
            }
            else if(i!='#'){
                a1.push_back(i);
            }
        }
        for(auto i : t){
            if(i=='#' && a2.size()>0){
                a2.pop_back();
            }
            else if (i!='#'){
                a2.push_back(i);
            }
        }
        
        for(auto i : a1){
            cout<<i;
        }
        cout<<endl;
        for(auto i : a2){
            cout<<i;
        }
        return a1==a2;
    }
};