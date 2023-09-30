//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        vector<int> pre(n),suf(n);
        pre[0] = arr[0];
        suf[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            pre[i] = min(pre[i-1],arr[i]);
            suf[n-i-1] = max(suf[n-i],arr[n-i-1]);
        }
        int i=0,j=0,ans=0;
        while(i<n&&j<n){
            if(pre[i]<=suf[j]){
                ans = max(ans,(j-i));
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends