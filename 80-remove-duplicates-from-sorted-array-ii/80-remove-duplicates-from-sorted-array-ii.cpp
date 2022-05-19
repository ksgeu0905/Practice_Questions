class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int i=0;
        for(auto it:m){
            if(it.second>=2){
                nums[i+1]=nums[i]=it.first;
                i+=2;
            }
            else{
                nums[i]=it.first;
                i++;
            }
        }
        return i;
    }
};