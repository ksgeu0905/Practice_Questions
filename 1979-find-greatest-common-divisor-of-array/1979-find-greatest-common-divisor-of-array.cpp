class Solution {
public:
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        int mi=*min_element(nums.begin(),nums.end());
                return gcd(ma,mi);

    }
};