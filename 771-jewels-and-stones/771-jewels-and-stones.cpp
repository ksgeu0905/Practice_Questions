class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int x=0;
        for(auto i : jewels){
            for(auto j :stones){
                if(i==j)x++;
            }
        }
        return x;
    }
};