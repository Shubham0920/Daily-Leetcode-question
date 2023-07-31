//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int changes[3]={0,0,0};
        if(bills[0] > 5){
            return false;
        }
        else{
            changes[0] ++;
        }
        for(int i=1;i<bills.size();i++){
            if(bills[i]==5){
                changes[0]++;
            }
            if(bills[i] == 10){
               if(changes[0]>=1){
                   changes[0]--;
                   changes[1]++;
               }
               else{
                   return 0;
               }
            }
            if (bills[i] == 20){
                if(changes[1]>=1 && changes[0]>=1){
                   changes[1]--;
                   changes[0]--;
                   changes[2]++;
               }
               else if(changes[0]>=3){
                   changes[0]-=3;;
                   changes[2]++;
               }
               else{
                   return 0;
               }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends