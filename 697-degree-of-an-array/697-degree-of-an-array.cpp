class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        int fre=-1;
        for(auto i :nums){
            mp[i]++;
        }
        for(auto it:mp){
            if(it.second > fre){
                fre=it.second;
            }
        }
        vector<int> v;
        for(auto it:mp){
            if(fre==it.second){
                v.push_back(it.first);
            }
        }
        int min=INT_MAX;
        for(int i=0;i<v.size();i++){
            int s=0,e=nums.size()-1;
            while(nums[s]!=v[i])
                s++;
            while(nums[e]!=v[i])
                e--;
            if(min > e-s+1)
                min=e-s+1;
            
        }
        return min;
        
    }
};