//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int a[], int n)
    {
      //Your code here
      vector<int> left_smaller(n);
      stack<int> st1;
      
      for(int i=0;i<n;i++){
          while(!st1.empty() && st1.top()>=a[i]){
              st1.pop();
          }
          if(st1.empty()){
              left_smaller[i] = 0;
          }
          else{
              left_smaller[i] = st1.top();
          }
          st1.push(a[i]);
      }
      vector<int> right_smaller(n);
      stack<int> st2;
      
      for(int i=n-1;i>=0;i--){
          while(!st2.empty() && st2.top()>=a[i]){
              st2.pop();
          }
          if(st2.empty()){
              right_smaller[i] = 0;
          }
          else{
              right_smaller[i] = st2.top();
          }
          st2.push(a[i]);
      }
      int ans = INT_MIN;
      for(int i=0;i<right_smaller.size();i++){
          ans = max(ans,abs(right_smaller[i]-left_smaller[i]));
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends