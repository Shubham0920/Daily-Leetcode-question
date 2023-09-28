//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    int pre[n];
    pre[0] = arr[0];
    int suf[n];
    suf[n-1] = arr[n-1];
    for(int i=1;i<n;i++){
        pre[i] = max(pre[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = min(suf[i+1],arr[i]);
    }
    for(int i=1;i<n-1;i++){
        if(pre[i] == suf[i]) return arr[i];
    }
    return -1;
}