class Solution {
public:
    int minSteps(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0,c=0;
        while(i<s.length() && j< t.length()){
            if(s[i]==t[j]){
                i++;j++;
            }
            else if(s[i]< t[j]){
                c++;
                i++;
            }
            else{
                c++;
                j++;
            }
        }
        while(i<s.length())
        {
            c++;
            i++;
        }
        while(j<t.length()){
            c++;
            j++;
        }
        return c;
    }
};