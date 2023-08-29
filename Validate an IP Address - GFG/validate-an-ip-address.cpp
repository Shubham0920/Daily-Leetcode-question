//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int digit(int s){
            if(s==0) return 1;
            int ans = 0;
            while(s>0){
                // if(s[i]<'0' && s[i]>)
                ans++;
                s=s/10;
            }
            return ans;
        }
        int stoi_(string s){
            int ans = 0;
            for(int i=0;i<s.size();i++){
                ans = ans*10 + s[i]-'0';
            }
            return ans;
        }
        int isValid(string s) {
            // code here
            int dot = 0;
            string ans = "";
            for(int i=0;i<s.size();i++){
                if(s[i] != '.'){
                    ans += s[i];
                }
                else{
                    dot++;
                    if(ans == "")return 0;
                    int p = stoi_(ans);
                    if(digit(p) != ans.size())return 0;
                    if(p>=0 && p<=255){
                        ans = "";
                        
                    }
                    else{
                        return 0;
                    }
                }
            }
                    if(dot!=3)return 0;
                    if(ans == "")return 0;
                    int p = stoi_(ans);
                    if(digit(p) != ans.size())return 0;
                    if(p>=0 && p<=255){
                        ans = "";
                        
                    }
                    else{
                        return 0;
                    }
            
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends