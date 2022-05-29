class Solution {
public:
    int titleToNumber(string columnTitle) {
        int j=0;
        int ans=0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            int d=columnTitle[i]-'A'+1;
            ans+=(d*pow(26,j));
            j++;
        }
        return ans;
    }
};