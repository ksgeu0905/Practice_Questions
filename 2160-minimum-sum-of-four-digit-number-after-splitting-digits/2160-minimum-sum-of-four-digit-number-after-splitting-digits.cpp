class Solution {
public:
    int minimumSum(int num) {
        string str=to_string(num);
        sort(str.begin(),str.end());
        string str1="",str2="";
        for(int i=0;i<4;i++){
            if(i%2==0)
                str1+=str[i];
            else
                str2+=str[i];
        }
        
        stringstream geek(str1);
 
        int x = 0,y=0;
        geek >> x;
        
        stringstream geek2(str2);
        geek2>>y;

        
        return x+y;
    }
};