class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int sum=accumulate(piles.begin(),piles.end(),0);
        for(auto i:piles){
            q.push(i);
        }
        while(k--){
              int x=q.top()/2;
              sum-=x;
              int y=q.top()-x;
              q.pop();
              q.push(y);
        }
        return sum;
    }
};