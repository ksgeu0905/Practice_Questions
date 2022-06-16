class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> la(n);
        vector<int> ra(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.empty()){
                la[i]=-1;
            }
            else{
                la[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ra[i]=n;
            }
            else{
                ra[i]=st.top();
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,(ra[i]-la[i]-1)*h[i]);
        }
        
        return ans;
    }
};