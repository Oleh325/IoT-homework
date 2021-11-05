#include <stdio.h>
#include <stdlib.h>
// For some reason Visual Studio wants scanf to be changed to scanf_s
#define scanf scanf_s

int main()
{
    int sizeOfArr1, sizeOfArr2, k, * arr1, * arr2, * differentElements;
    // Inputting array sizes
    printf("Input sizeOfArr1: ");
    scanf("%d", &sizeOfArr1);
    printf("Input nsizeOfArr2: ");
    scanf("%d", &sizeOfArr2);

    // Allocating memory for the arrays
    arr1 = (int*)malloc(sizeOfArr1 * sizeof(int));
    arr2 = (int*)malloc(sizeOfArr2 * sizeof(int));
    // Allocating memory for resulting array with a size of the smallest array among these two above
    differentElements = (int*)malloc((sizeOfArr1 <= sizeOfArr2 ? sizeOfArr1 : sizeOfArr2) * sizeof(int));
    // Inputting arrays' elements
    for (int i = 0; i < sizeOfArr1; i++)
    {
        printf("Input arr1[%d]: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < sizeOfArr2; i++)
    {
        printf("Input arr2[%d]: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Calling our function, that returns the amount of elements in our resulting array
    k = array_diff(sizeOfArr1, sizeOfArr2, arr1, arr2, differentElements);
    // Deleting memory that haven't been used
    differentElements = realloc(differentElements, k*sizeof(int));

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
            printf("differentElements[%d] = %d\n", i + 1, differentElements[i]);
        }
    }

    free(arr1);
    free(arr2);
    free(differentElements);
}






int array_diff(int sizeOfArr1, int sizeOfArr2, int* arr1, int* arr2, int* differentElements)
{
    // Setting the amount of elements in resulting array to 0 
    int k = 0;
    for (int i = 0; i < sizeOfArr2; i++)
    {
        for (int j = 0; j < sizeOfArr1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                break; // If we found same number in two arrays we skip to the next element in arr2
            }
            if (j == sizeOfArr1 - 1) // If we come to an end of internal loop and haven't found same number in arr1, that we have in arr2
            {
                int m = 0; // Counter for do while loop
                do
                {
                    if (arr2[i] != differentElements[m]) // If we don't have in our relusting array the number we found, we add the number to resulting array
                    {
                        differentElements[k] = arr2[i];
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