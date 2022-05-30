class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        for(auto i : ops){
            if(i=="+"){
                int n=ans.size();
                ans.push_back(ans[n-1]+ans[n-2]);
            }
            else if(i=="C"){
                ans.pop_back();
            }
            else if(i=="D"){
                 int n=ans.size();
                ans.push_back(ans[n-1]*2);
            }
            else{
                int x=stoi(i);
                ans.push_back(x);
            }
            
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};