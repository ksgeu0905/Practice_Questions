class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int i=1;
        int ans=0;
        int c=piles.size()/3;
        while(c--){
            ans+=piles[i];
            i+=2;
        }
        return ans;
    }
};