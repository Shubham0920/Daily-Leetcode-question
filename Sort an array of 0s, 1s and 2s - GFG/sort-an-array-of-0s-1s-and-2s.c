// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{   
    int z = 0,o = 0,t=0;
    for(int i=0;i<n;i++){
        if(a[i] == 0) z++;
        if(a[i] == 1) o++;
        if(a[i] == 2) t++;
    }
    int i=0;
    while(z--){
        a[i] = 0;
        i++;
    }
    while(o--){
        a[i] = 1;
        i++;
    }
    while(t--){
        a[i] = 2;
        i++;
    }
    
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends