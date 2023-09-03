//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void merge(vector<int>&cnt,vector<pair<int,int>>&v,int low,int mid,int high ){
      vector<pair<int,int>>tmp(high-low+1);
      int i=low,j=mid+1,k=0;
      while(i<=mid and j<=high){
          if(v[i].first<=v[j].first){
              tmp[k++]=v[j++];
          }
          else {
              cnt[v[i].second]+=high-j+1;
              tmp[k++]=v[i++];
          }
      }
      while(i<=mid){
          tmp[k++]=v[i++];
      }
      while(j<=high){
          tmp[k++]=v[j++];
      }
      for(int i=low;i<=high;i++)v[i]=tmp[i-low];
  }
   void mergesort(vector<int>&cnt,vector<pair<int,int>>&v,int low ,int high){
       if(low<high){
      int mid= low+(high-low)/2;
       mergesort(cnt,v,low,mid);
       mergesort(cnt,v,mid+1,high);
       merge(cnt,v,low,mid,high);
       }
   }
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	   
	    
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        vector<int>ans(n,0);
        mergesort(ans,v,0,n-1);
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends