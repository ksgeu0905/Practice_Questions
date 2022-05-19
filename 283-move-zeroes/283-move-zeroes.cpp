class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(auto i=nums.begin();i!=nums.end();++i){
            if(*i == 0){
                 c++;
                 nums.erase(i);
                 i--;
            }
        }
        while(c--)
            nums.push_back(0);
        
    }
};