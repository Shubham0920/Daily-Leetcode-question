//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int l = 0;
        int h = arr.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
                return arr[mid];
            }
            if(arr[mid]>arr[mid-1]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        // cout<<l<<h<<endl;
        return arr[arr.size()-1];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends