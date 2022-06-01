class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        vector<int> arr(prices.size());
        
        for(int i=0;i<prices.size();i++){
            if(s.empty() || prices[s.top()]<prices[i]){
                s.push(i);
            }
            else{
                while(!s.empty() && prices[i] <= prices[s.top()]){
                    arr[s.top()]=prices[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        
        for(int i=0;i<prices.size();i++){
            prices[i]-=arr[i];
        }
        return prices;
    }
};