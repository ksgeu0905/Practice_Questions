class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int z=0,i;
        for(i=1;i<=n;i++){
            if(i==target[z]){
                ans.push_back("Push");
                z++;
                if(z==target.size())
                    break;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};