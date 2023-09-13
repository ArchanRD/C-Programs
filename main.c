#include <stdio.h>

void traverse(int arr[], int n);
void insertion(int arr[], int n);
void deletion(int arr[], int n);
void updation(int arr[], int n);
void search(int arr[], int n);

void main()
{
    int arr[100], n, index, choice;

    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    // Traverse
    traverse(arr, n);

    do
    {
        printf("Select a choice: ");
        printf("\n1. Traverse");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Updation");
        printf("\n5. Search");
        printf("\n6. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;
        case 2:
            insertion(arr, n);
            break;
        case 3:
            deletion(arr, n);
            break;
        case 4:
            updation(arr, n);
            break;
        case 5:
            search(arr, n);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 6);

    printf("\n\n");
}

/*
    Traverse function is used to print
    all the elements of an array one by
    one.
*/
void traverse(int arr[], int n)
{
    printf("-------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d index holds: %d", i, arr[i]);
    }
    printf("\n-------------------");

    printf("\n");
}

void insertion(int arr[], int n)
{
    int insertion_index, insertion_val;
    if (n > 0)
    {
        printf("\nEnter the index point of the insertion: ");
        scanf("%d", &insertion_index);

        if (insertion_index > n)
        {
            printf("\nThe entered index is not valid");
        }
        else
        {
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &insertion_val);
            /*
                The value of n is increased by 1 as the
                insertion will add an element to the array,
                so the length of the array will be increased by 1.

                Here n represents the total number of elements in
                an array or length of the array.
            */
            n += 1;
            for (int i = n - 1; i > insertion_index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[insertion_index] = insertion_val;
            traverse(arr, n);
        }
    }
}

void deletion(int arr[], int n)
{
    int deletion_index;
    printf("\nEnter the index to be deleted: ");
    scanf("%d", &deletion_index);

    for (int i = deletion_index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
        /*
            On deleting an element, we are
            reducing the size of array, hence updating
            the value of n by minus 1.
        */
    }
    n -= 1;
    traverse(arr, n);
}

void updation(int arr[], int n)
{
    int update_index, update_val;
    printf("\nEnter the index to be updated: ");
    scanf("%d", &update_index);
    if (update_index > n)
    {
        printf("\nThe entered index doesnt exists.");
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d", &update_val);
        arr[update_index] = update_val;
    }
    traverse(arr, n);
}

void search(int arr[], int n)
{
    int search_index, search_val;
    printf("\nEnter the index to be searched: ");
    scanf("%d", &search_index);

    if (search_index > n)
    {
        printf("\nThe entered search index doesnt exists");
    }
    else
    {
        printf("\nThe index %d hold value: %d", search_index, arr[search_index]);
    }
    traverse(arr, n);
}