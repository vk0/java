//C program for Merge Sort
#include<stdlib.h>
#include<stdio.h>

// Merges two sub-arrays A[l..m] and A[m+1..r].
// l->left most index, r->right most index, m->middle index
void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    //Find sizes of two sub-arrays to be merged
    int nL = m - l + 1;
    int nR =  r - m;

    /* create temp Arrays left[] and right[]
    and copy data from main array */
    int left[nL], right[nR];
    for (i = 0; i < nL; i++)
        left[i] = A[l + i];
    for (j = 0; j < nR; j++)
        right[j] = A[m + 1 + j];

    /* Merge the temp Arrays back into A[l..r]*/
    i = 0; // Initial index of first subArray
    j = 0; // Initial index of second subArray
    k = l; // Initial index of merged subArray

    /* Comparing left[] and rigth[], sub-array with
        smaller element get copy to main array A[]*/
    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left[], if there
       are any */
    while (i < nL)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if there
       are any */
    while (j < nR)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-Array of A to be sorted */
void merge_sort(int A[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for large l
        int mid = l + (r - l) / 2; //mid is middle index

        // Sort first and second halves
        merge_sort(A, l, mid); //Firstly left half is recursively call
        merge_sort(A, mid + 1, r); // Then right half is recursively call

        merge(A, l, mid, r); //merge function call
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an Array */
void printArr(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Program to test above functions */
int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(A) / sizeof(A[0]);

    printf("Unsorted Array: \n");
    printArr(A, arr_size); // Print unsorted array

    merge_sort(A, 0, arr_size - 1);

    printf("\nSorted Array: \n");
    printArr(A, arr_size);// Print sorted array
    return 0;
}