class Solution {
public:
    int minOperations(vector<string>& logs) {
        int x=0;
        for(auto i : logs){
            if(i=="../"){
                x--;
                if(x<0){
                    x=0;
                }
            }
            else if( i=="./"){
                x=x;
            }
            else{
                x++;
            }
        }
       
        return x;
    }
};