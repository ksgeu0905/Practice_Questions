class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        string ans="";
        int n=num1.size(),m=num2.size();
        
        vector<int>mul(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                mul[i+j+1]+= (num1[i]-'0')*(num2[j]-'0');
                mul[i+j] += mul[i+j+1]/10;
                mul[i+j+1]=mul[i+j+1]%10;
            }
        }
        int k=0;
        while(mul[k]==0)k++;
        for(int i=k;i<mul.size();i++){
            ans+=(char)(mul[i]+48);
        }
        return ans;
        
    }
};