class Solution {
public:
    string convert(string s, int numRows) {
        char arr[numRows][1000];
        memset(arr,'#',sizeof(arr));
        int n=0;
        int i=0,j=0,f=0;
                
        while(n<s.length()){
            for(i=0;i<numRows;i++){
                arr[i][j]=s[n];
                n++;
                if(n>=s.length()){
                    f=1;
                    break;
                }
            }
            if(f==1)break;
            i=i-2;
            j=j+1;
            while(i>0){
                arr[i][j]=s[n++];
                if(n>=s.length()){
                    f=1;
                    break;
                }
                i--;
                j++;
                
            }
             if(f==1)break;
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int x=0;x<=j;x++){
               if(arr[i][x]!='#')
                   ans+=arr[i][x];
            }
            
        }
        return ans;
    }
};