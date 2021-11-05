#include <stdio.h>
#include <stdlib.h>
// For some reason Visual Studio wants scanf to be changed to scanf_s
#define scanf scanf_s

int main()
{
    int n1, n2, k, * arr1, * arr2, * arrd;
    // Inputting array sizes
    printf("Input n1: ");
    scanf("%d", &n1);
    printf("Input n2: ");
    scanf("%d", &n2);

    // Allocating memory for the arrays
    arr1 = (int*)malloc(n1 * sizeof(int));
    arr2 = (int*)malloc(n2 * sizeof(int));
    // Allocating memory for resulting array with a size of the smallest array among these two above
    arrd = (int*)malloc((n1 <= n2 ? n1 : n2) * sizeof(int));
    // Inputting arrays' elements
    for (int i = 0; i < n1; i++)
    {
        printf("Input arr1[%d]: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        printf("Input arr2[%d]: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Calling our function, that returns the amount of elements in our resulting array
    k = array_diff(n1, n2, arr1, arr2, arrd);
    // Deleting memory that haven't been used
    arrd = realloc(arrd, k*sizeof(int));

    // Printing the result
    if (k == 0)
    {
        printf("There's no such array, that contains elements from arr2 which are not present in arr1\n");
    }
    else
    {
        printf("Array, that contains elements from arr2 which are not present in arr1:\n");
        for (int i = 0; i < k; i++)
        {
            printf("arrd[%d] = %d\n", i + 1, arrd[i]);
        }
    }

    free(arr1);
    free(arr2);
    free(arrd);
}






int array_diff(int n1, int n2, int* arr1, int* arr2, int* arrd)
{
    // Setting the amount of elements in resulting array to 0 
    int k = 0;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                break; // If we found same number in two arrays we skip to the next element in arr2
            }
            if (j == n1 - 1) // If we come to an end of internal loop and haven't found same number in arr1, that we have in arr2
            {
                int m = 0; // Counter for do while loop
                do
                {
                    if (arr2[i] != arrd[m]) // If we don't have in our relusting array the number we found, we add the number to resulting array
                    {
                        arrd[k] = arr2[i];
                        k++;
                    }
                    m++;
                } while (m < k);
            }
        }
    }

    // Returning the amount of elements in our resulting array
    return k;
}