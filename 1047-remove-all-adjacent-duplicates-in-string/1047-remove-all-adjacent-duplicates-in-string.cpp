class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> temp;
        for(int i=0;i<s.size();i++)
        {
            
           
                if(!temp.empty() && temp.top()==s[i])
                    temp.pop();
                else
                    temp.push(s[i]);
            
        }
        string s1="";
        while(!temp.empty())
        {
            s1=temp.top()+s1;
            temp.pop();
            
        }
        
        return s1;
    }
};