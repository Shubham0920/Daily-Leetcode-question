//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long  largestRectangleArea(long long h[],int n) {
        // int n = h.size();
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            }
            else{
                left[i] = st.top()+1;
            }
            st.push(i);
        }

        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && h[st1.top()]>=h[i]){
                st1.pop();
            }
            if(st1.empty()){
                right[i] = n-1;
            }
            else{
                right[i] = st1.top()-1;
            }
            st1.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]+1)*h[i]);
        }

        return ans;
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        return largestRectangleArea(arr,n);
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends