// You are given an array A containing N positive integers. Find the number of pairs (i,j) such that 1≤i<j≤N and:
// Ai+Aj≥Ai⋅Aj
// Input
#include <bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}

int main(){
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++){
          cin>>a[i];
      }
      reverse(a,a+k);
      reverse(a+k,a+n);
      reverse(a,a+n);
      for(int i=0;i<n;i++){
          cout<<a[i]<<" ";
      }
      cout<<endl;
    }        
    return 0;
}