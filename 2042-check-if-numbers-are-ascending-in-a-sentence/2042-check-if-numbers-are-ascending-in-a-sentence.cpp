class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev=INT_MIN;
        int flag = 0;
        for(int i = 0 ; i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9' &&(s[i+1]=='\0' || s[i+1]==' '))
            {
                int x = s[i]-'0';
                if(prev<x) prev = x;
                else if(prev>=x)
                {
                    flag = 1;
                    break;
                }
            }
            else  if(s[i]>='0' && s[i]<='9' && s[i+1]!=' ') 
            {
                int x = (s[i]-'0' )*10 +s[i+1]-'0';
                i++;
                if(prev<x)
                    prev=x;
                else if(prev>=x)
                {
                    flag = 1;
                    break;
                }
            }
            
        }
        if(flag==1)
            return false;
        return true;
    }
    
};