//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
	    string ans="";
	    int quo=n/d;
	    ans+=to_string(quo);
	    int rem=n%d;
	    if(rem==0){
	        return ans;
	    }
	    else{
	        ans+='.';
	        map<int,int>mp;
	        while(rem!=0){
	            if(mp.find(rem)!=mp.end()){
	                int pos=mp[rem];
	                ans.insert(pos,"(");
	                ans+=')';
	                return ans;
	            }
	            else{
	                mp[rem]=ans.length();
	                rem*=10;
	                quo=rem/d;
	                rem = rem%d;
	                ans+=to_string(quo);
	            }
	        }
	        
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends