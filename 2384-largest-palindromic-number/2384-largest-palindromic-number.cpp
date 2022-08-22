class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>freq(10,0);
        for(auto i:num){
            freq[i-'0']++;
        }
        if(freq[0]==num.length())
            return "0";
        string ans="";
        if(freq[0]==num.length()-1){
            for(int i=9;i>0;i--){
                if(freq[i]>0){
                    ans+=to_string(i);
                    return ans;
                }
            }
        }
        
        for(int i=9;i>=0;i--){
            while(freq[i]>1){
                ans+=to_string(i);
                freq[i]-=2;
            }
        }
        string t=ans;
        reverse(t.begin(),t.end());
        for(int i=9;i>=0;i--){
            if(freq[i]>0){
                ans+=to_string(i);
                break;
            }
        }
        return ans+t;
    }
};