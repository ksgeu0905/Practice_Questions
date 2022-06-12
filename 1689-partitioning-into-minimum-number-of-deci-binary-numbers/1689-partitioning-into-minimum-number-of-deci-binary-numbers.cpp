class Solution {
public:
    int minPartitions(string n) {
       char a='0';
       for(auto i : n){
           a=max(a,i);
       }
        return a-'0';
    }
};