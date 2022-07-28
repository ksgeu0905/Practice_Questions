class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans=0;
        for(int i=brackets.size()-1;i>0;i--){
            brackets[i][0]-=brackets[i-1][0];
        }
        
        for(int i=0;i<brackets.size();i++){
            if(income<=0)
                break;
            int x=min(income,brackets[i][0]);
            ans+=x*(brackets[i][1]/100.0);
            income-=x;
        }
        return ans;
    
    }
};