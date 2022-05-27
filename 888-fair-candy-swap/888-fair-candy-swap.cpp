class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1=accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sum2=accumulate(bobSizes.begin(),bobSizes.end(),0);
        set<int>sb;
        for(auto i : bobSizes){
            sb.insert(i);
        }
        int delta=(sum2-sum1)/2;
        vector<int>ans;
        for(int i=0;i<aliceSizes.size();i++){
            auto it=sb.find(aliceSizes[i]+delta);
            if(it!=sb.end()){
                ans.push_back(aliceSizes[i]);
                ans.push_back(aliceSizes[i]+delta);
                return ans;
            }
        }
        return ans;

    }
};