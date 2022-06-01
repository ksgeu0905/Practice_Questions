class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(auto i :s){
            int x=i-96;
            if(x<=9){
                sum+=x;
            }
            else{
                sum+=x%10 +x/10;
            }
        }
        int ex;
        while(k>1){
            ex=0;
            while(sum>0){
                ex+=(sum%10);
                sum=sum/10;
            }
            sum=ex;
            if(sum<=9)
                return sum;
            k--;
        }
        return sum;
    }
};