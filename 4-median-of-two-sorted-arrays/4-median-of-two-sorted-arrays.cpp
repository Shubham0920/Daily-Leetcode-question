class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        
        int n1=arr1.size();
        int n2=arr2.size();
        vector<int> arr3(n1+n2);
        int i = 0, j = 0, k = 0;
 
        while (i<n1 && j <n2)
        {
            if (arr1[i] < arr2[j])
                arr3[k++] = arr1[i++];
            else
                arr3[k++] = arr2[j++];
        }

        while (i < n1)
            arr3[k++] = arr1[i++];

        while (j < n2)
            arr3[k++] = arr2[j++];
        
        if(arr3.size()%2!=0){
            return (double)arr3[arr3.size()/2];
        }
        else{
            return (double)(arr3[(arr3.size()/2)-1]+arr3[(arr3.size()/2)])/2;
        }
        
    }
};