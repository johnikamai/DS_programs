#include<stdio.h>
int main()
{
    int a[100], n, i, X, flag = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array values:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter value to search: ");
    scanf("%d", &X);
    for (i = 0; i < n; i++)
    {
        if (X == a[i])
        {
            printf("Element is found");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Element is not found");
    return 0;
}
