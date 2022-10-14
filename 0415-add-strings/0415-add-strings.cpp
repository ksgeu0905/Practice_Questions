class Solution {
public:
    string addStrings(string nums, string nums2) {
        string s="";
        int i=nums.length()-1,j=nums2.length()-1;
        int c=0,x;
        while(i>=0 && j>=0){
            x=nums[i]+nums2[j]-96;
            x+=c;
            if(x>9)c=1;
            else c=0;
            s=((char)(x%10+48))+s;
            i--;j--;
        }
        while(i>=0){
            x=nums[i]-48;
            x+=c;
            if(x>9)c=1;
            else c=0;
            s=((char)(x%10+48))+s;
            i--;
        }
        while(j>=0){
            x=nums2[j]-48;
            x+=c;
            if(x>9)c=1;
            else c=0;
            s=((char)(x%10+48))+s;
            j--;
        }
        if(c==1)s='1'+s;
        
        
        return s;
    }
};