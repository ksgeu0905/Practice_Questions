class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26]={0};
        for(int i=0 ;i<s.length();i++){
            arr[s[i]-'a']=i;
        }
        vector<int> ans;
        int prev=-1,max=arr[s[0]-'a'];
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']>max)
                max=arr[s[i]-'a'];
            if(i==max){
                ans.push_back(max-prev);
                prev=max;
            }
        }
        return ans;
    }
};