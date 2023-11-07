#include <stdio.h>
#include <stdlib.h>
void printarry(int arr[], int n)
{
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n, int exp)
{
    int out[n];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        out[--count[(arr[i] / exp) % 10]] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}

void radixsort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int i = 1; max / i > 0; i = i * 10)
    {
        countsort(arr, n, i);
    }
}

int main()
{
    int arr[10] = {136, 487, 358, 469, 570, 247, 598, 639, 205, 609};
    int n = 10;
    // printf("%d",n);
    radixsort(arr, n);
    printarry(arr, n);
    return 0;
}
