class Solution {
public:
    int tribonacci(int n) {
        int x=0,y=1,z=1;
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        n=n-2;
        int curr;
        while(n--){
            curr=x+y+z;
            x=y;
            y=z;
            z=curr;
        }
        return curr;
        
    }
};