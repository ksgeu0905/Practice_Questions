class Solution {
public:
    int tribonacci(int n) {
        int z=0,o=1,t=1;
        if(n==0)return 0;
        if(n<=2)return 1;
        for(int i=3;i<=n;i++){
            int x = z+o+t;
            z=o;
            o=t;
            t=x;
        }
        return t;
    
    }
};