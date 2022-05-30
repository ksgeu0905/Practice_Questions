class Solution {
public:
    void fun(vector<int> nums,int ind,set<vector<int>>&s,vector<int>temp){
        if(ind>=nums.size())
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        fun(nums,ind+1,s,temp);
        temp.pop_back();
        fun(nums,ind+1,s,temp);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;
        fun(nums,0,s,temp);
        for(auto i :s){
            ans.push_back(i);
        }
        return ans;
    }
};