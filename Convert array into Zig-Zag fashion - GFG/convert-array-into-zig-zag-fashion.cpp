// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void swap(int arr[],int p1,int p2)
{
    int t=arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=t;
}
void zigZag(int arr[], int n) {
    // code here
    for(int i=0;i<n-1;i++)
    {
        if(i%2==0)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr,i,i+1);
            }
        }
        else
        {
            if(arr[i]<arr[i+1])
            {
                swap(arr,i,i+1);
            }
        }
    }
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends