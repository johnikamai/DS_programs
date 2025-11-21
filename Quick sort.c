#include <stdio.h>  
void printArray(int arr[ ], int size)  
{  
    for (int i = 0; i < size; i++)  
    {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
void partition(int arr[], int size, int p, int *leftSize, int *rightSize)  
{  
    int left[size], right[size];  
    *leftSize = 0;  
    *rightSize = 0;  
   for (int i = 0; i < size; i++)  
    {  
        if (arr[i] < p)  
        {  
            left[(*leftSize)++] = arr[i];  
        }  
        else if (arr[i] > p)  
        {  
            right[(*rightSize)++] = arr[i];  
        }  
    }  
    for (int i = 0; i < *leftSize; i++)  
    {  
        arr[i] = left[i];  
    }  
     arr[*leftSize] = p;  
   for (int i = 0; i < *rightSize; i++)  
    {  
        arr[*leftSize + i + 1] = right[i];  
    }  
}  
  
void quickSort(int arr[], int size)  
{  
    if (size < 2)  
    {  
        return; // array is already sorted  
    }  
  int left[size], right[size];  
    int p = arr[0];  
    int leftSize, rightSize; 
    partition(arr, size, p, &leftSize, &rightSize);  
   quickSort(arr, leftSize);  
    quickSort(arr + leftSize + 1, rightSize);  
    printArray(arr, size);  
}  
int main()  
{  
    int n;  
    scanf("%d", &n);  
   int arr[n];  
    for (int i = 0; i < n; ++i)  
    {  
        scanf("%d", &arr[i]);  
    }  
    quickSort(arr, n);  
    return 0;  
}  
