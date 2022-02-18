// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    float gap = (n+m);
	    while(gap>=1){
	        gap = ceil(gap/2);
	       // int x = gap; ;
	        int first = 0;
	        int last = gap;
	       // cout<<"gap "<<gap<<endl;
	        for(int i = last; i<(n+m); i++,first++){
	            if(first <n && i < n){
	                if(arr1[first] > arr1[i]){
	                   // cout<<arr1[first]<<" "<<arr1[i]<<endl;
	                    swap(arr1[first],arr1[i]);
	                }
	            }
	            if(first < n && i >= n){
	                if(arr1[first] > arr2[i-n]){
	                   // cout<<arr1[first]<<" "<<arr2[i-n]<<endl;
	                    swap(arr1[first],arr2[i-n]);
	                }
	            }
	            if(first >= n && i >= n){
	                if(arr2[first-n] > arr2[i-n]){
	                   // cout<<arr2[first-n]<<" "<<arr2[i-n]<<endl;
	                    swap(arr2[first-n],arr2[i-n]);
	                }
	            }
	        }
	        if(gap == 1){
	            break;
	        }
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends