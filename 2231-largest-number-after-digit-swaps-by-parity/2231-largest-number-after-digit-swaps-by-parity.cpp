class Solution {
public:
    
    int largestInteger(int num) {
        int rem=0;
        string s=to_string(num);
        priority_queue<int> odd,even;
        while(num>0){
            rem=num%10;
            if(rem%2==0)
                even.push(rem);
            else
                odd.push(rem);
            num/=10;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            rem=s[i]-'0';
            if(rem%2==0){
                ans=ans*10+even.top();
                even.pop();
            }
            else{
                ans=ans*10+odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};