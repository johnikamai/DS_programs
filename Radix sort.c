#include <stdio.h> 
// helper function to get maximum of array 
int getMax(int arr[], int n) { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] > mx) { 
            mx = arr[i]; 
        } 
    } 
    return mx; 
} 
 
// viewing the array 
void peek(int *arr, int size) { 
    for (int i = 0; i < size; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
// radix_sort function 
void radix_sort(int *arr, int n) 
{ 
   // code here 
   int e = 1; 
   int m = getMax(arr, n); 
   int buckets[10][n]; 
   while (m) { 
       int count[10] = {}; 
       for (int i = 0; i < n; i++) { 
           int pos = (arr[i] / e)%10; 
           buckets[pos][count[pos]++] = arr[i]; 
       } 
       int k = 0; 
       for (int i = 0; i < 10; i++) { 
           for (int j = 0; j < count[i]; j++) { 
               arr[k++] = buckets[i][j]; 
           } 
       } 
       e *= 10; 
       m /= 10; 
   } 
} 
 
 
 
int main () { 
    int arr[5] = {64, 25, 12, 22, 11}; 
    printf("Before sorting\n"); 
    peek(arr, 5); 
    // function call 
    radix_sort(arr, 5); 
    printf("After sorting\n"); 
    peek(arr, 5); 
} 
