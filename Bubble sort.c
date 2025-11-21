#include<stdio.h>
int main()
{
    int a[100], n, i, j, temp;
    printf("Enter array size");
    scanf("%d", &n);
    printf("Enter array values");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
