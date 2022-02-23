// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> even;
    vector<int> odd;
        for(int i=0; i<n; i++) {
       if(arr[i]>=0) {
           even.push_back(arr[i]);
       }
       else {
           odd.push_back(arr[i]);
       }
   }
   int j=0;
   for(int i=0; i<n; j++ ) {
       if(j<even.size()) {
           arr[i]=even[j];
           i++;
       }
       if(j<odd.size()) {
           arr[i]=odd[j];
           i++;
       }

   }
}
	   
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends