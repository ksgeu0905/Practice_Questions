class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        map<string,int> mp;
        int x=0,i=0,j=0;
        string temp="";
        for(auto str: cpdomains){
            i=0;
            j=str.length()-1;
            while(str[i]!=' '){
                temp+=str[i];
                i++;
            }
            x=stoi(temp);
            temp.clear();
            while(str[j]!=' '){
                if(str[j]=='.'){
                    mp[temp]+=x;
                    temp=str[j]+temp;
                }
                else{
                    temp=str[j]+temp;
                }
                j--;
            }
            mp[temp]+=x; 
            temp.clear();
        }
        for(auto m : mp){
            ans.push_back(to_string(m.second)+" "+m.first);
        }
        return ans;
    }
};