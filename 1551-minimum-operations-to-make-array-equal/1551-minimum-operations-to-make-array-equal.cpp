class Solution {
public:
    int minOperations(int n) {
        int c=0;
        int i=1;
        while(i<n){
            c+=(n-i);
            i+=2;
        }
        return c;
    }
};