class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        
        for(int i=0;i < nums.size();i++){
            if(st.empty() || nums[i] <= nums[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && nums[i] > nums[st.top()]){
                    ans[st.top()]=nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        for(int i=0;i< nums.size() ;i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            if(st.empty())break;
        }
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
    }
};