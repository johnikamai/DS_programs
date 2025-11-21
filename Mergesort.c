#include <stdio.h>  
// Merge two subarrays L and R into array a   
void merge(int a[], int lb, int mid, int ub)  
{  
    int b[ub - lb + 1]; // Auxiliary array for merging  
    int i = lb;  
    int j = mid + 1;  
    int k = 0; // Index for the auxiliary array  
    while (i <= mid && j <= ub)  
    {  
        if (a[i] <= a[j]) {  
            b[k] = a[i];  
            i++;  
        } else {  
            b[k] = a[j];  
            j++;  
        }  
        k++;  
    }  
    // Copy the remaining elements of the first subarray, if any   
    while (i <= mid) {  
        b[k] = a[i];  
        i++;  
        k++;  
    }  
    // Copy the remaining elements of the second subarray, if any   
    while (j <= ub) {  
        b[k] = a[j];  
        j++;  
        k++;  
    }  
  // Copy elements from the auxiliary array back to the original array a   
    for (k = 0; k < ub - lb + 1; k++) {  
        a[lb + k] = b[k];  
    }  
}  
// Divide the array into two subarrays, sort them, and merge them   
void mergeSort(int a[], int lb, int ub)  
{  
    if (lb < ub)  
    {  
        // mid is the point where the array is divided into two subarrays   
        int mid = lb + (ub - lb) / 2;  
          mergeSort(a, lb, mid);  
        mergeSort(a, mid + 1, ub);  
          // Merge the sorted subarrays   
        merge(a, lb, mid, ub);  
   // Print the array after each iteration   
        for (int i = lb; i <= ub; i++) {  
            printf("%d ", a[i]);
        }  
        printf("\n");  
    }  
}  
   int main()  
{  
    int n;  
    scanf("%d", &n);  
    int a[n];  
     for (int i = 0; i < n; i++)  
     scanf("%d", &a[i]);  
    mergeSort(a, 0, n - 1);  
       return 0;  
} 
