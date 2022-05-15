class Solution {
public:
    bool binary(vector<int>nums,int key,int s,int e){
        if(s>e)
            return false;
        int mid=s+(e-s)/2;
        if(nums[mid]==key)
            return true;
        if(nums[mid]<key)
            return binary(nums,key,mid+1,e);
        else
            return binary(nums,key,s,mid-1);          
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        set<int> ans;
        vector<int>a;
        for(int i=0;i<nums1.size();i++){
            if(binary(nums2,nums1[i],0,nums2.size()-1))
                ans.insert(nums1[i]);
        }
        for(auto it: ans)
            a.push_back(it);
        return a;
    }
};