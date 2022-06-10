class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int sum=0,size=0;
        map<char,int> m;
        int l=s.length();
        while(j<l){
            m[s[j]]++;
            sum++;
            if(m.size()==sum){
                size=max(size,j-i+1);
            }
            j++;
            while(sum>m.size()){
                m[s[i]]--;
                sum--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
        }
        return size;
    }
};