class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string c_pre="";
        int i=0;
        int min_len=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<min_len)
                min_len=strs[i].size();
        }
        for(int i=0;i<min_len;i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=c){
                    return c_pre;
                }
            }
            c_pre+=c;
        }
        return c_pre;
        
    }
};