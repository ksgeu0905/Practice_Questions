class Solution {
public:
    bool issubsequence(string& s1, string& s2)
    {
        int n = s1.length(), m = s2.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        return i == n;
    }
    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        for(int i=0;i<strs.size();i++){
            bool f=false;
            int cur=strs[i].length();
            for(int j=0;j<strs.size();j++){
                if(i!=j && issubsequence(strs[i],strs[j])){
                    f=true;
                    break;
                }
            }
            if(!f){
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};