class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],p=0;
        for(int i=1 ;i<prices.size();i++){
            p=max(p,prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        return p;
    }
};