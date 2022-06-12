class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i=0;i<boxes.length();i++){
            int c=0;
            for(int j=0;j<boxes.length();j++){
                if(boxes[j]=='1')c+=abs(j-i);
            }
            ans.push_back(c);
        }
        return ans;
    }
};