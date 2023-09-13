#include <stdio.h>

void traverse(int arr[], int n);

void main()
{
    int arr[100], i, j, n, index;
    int insertion_index, insertion_val;

    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    // Traverse
    traverse(arr, n);

    // Insertion
    if (n > 0)
    {
        printf("\nEnter the index point of the insertion: ");
        scanf("%d", &insertion_index);

        if (insertion_index > n)
        {
            printf("The entered index is not valid");
        }
        else
        {
            printf("Enter the value to be inserted: ");
            scanf("%d", &insertion_val);
            /*
                The value of n is increased by 1 as the
                insertion will add an element to the array,
                so the length of the array will be increased by 1.

                Here n represents the total number of elements in
                an array or length of the array.
            */
            n += 1;
            for (i = n - 1; i > insertion_index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[insertion_index] = insertion_val;
            traverse(arr, n);
        }
    }

    printf("\n\n");
}

void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d index holds: %d", i, arr[i]);
    }

    printf("\n");
}