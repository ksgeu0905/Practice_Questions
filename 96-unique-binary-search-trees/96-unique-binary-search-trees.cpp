class Solution {
public:
    int numTrees(int n) {
         //C(2n,n)/(n+1)
        long long ans =1;
        for(int i=n+1;i<=2*n;i++){
            ans = ans*i/(i-n);
        }
        return ans/(n+1);
    }
};