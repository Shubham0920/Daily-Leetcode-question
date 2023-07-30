//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        //  int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        vector<int> right(n);
        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                right[i] = n;
            }
            else{
                right[i] = st1.top();
            }
            st1.push(i);
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int ind = (right[i]-left[i]-2);
            // cout<<ind<<" "<<arr[i]<<endl;
            if(ans[ind]!=-1){
                ans[ind] = max(ans[ind],arr[i]);
            }
            else{
                ans[ind] = arr[i];
            }
        }
        for(int i = n-2;i>=0;i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends