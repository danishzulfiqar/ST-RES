#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BUBBLE_SORT     1
#define SELECTION_SORT  2
#define INSERTION_SORT  3
#define MERGE_SORT      4
#define QUICK_SORT 5


void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);
void merge_sort_array(int * ptr_array, int size);

int main()
{
    srand((unsigned int)time(NULL));
    int size;
    int sort_type;
    char run_again = 'y';

    while (run_again == 'y' || run_again == 'Y') {
        printf("Enter the array size: ");
        scanf("%d", &size);

        printf("Choose the sorting method:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n"); // Add this line
        printf("Enter the number corresponding to the sorting method: ");
        scanf("%d", &sort_type);

        int *my_array = (int *)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            my_array[i] = rand() % 1000;
        }

        double time_spent = 0.0;
        clock_t begin = clock();
        sort_array(my_array, size, sort_type);
        clock_t end = clock();
        print_array(my_array, size);
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n\nArray size: %d\n", size);
        printf("Time elapsed is %f milliseconds\n", time_spent * 1000);
        free(my_array);

        printf("\nDo you want to run the code again? (y/n): ");
        scanf(" %c", &run_again);
    }

    return 0;
}

void print_array(int * ptr_array, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%3d\t", *(ptr_array+i));

    }
}

void sort_array(int * ptr_array, int arr_size, int sort_type)
{
    switch(sort_type)
    {
        case BUBBLE_SORT:
        /****************** Implement Bubble Sort Here *************************/
         for(int k = arr_size; k>0; k--)
         {
            for(int i=0; i<k-1; i++)
            {
                if(*(ptr_array+i)>*(ptr_array+i+1))
                {
                    int temp = *(ptr_array+i+1);
                    *(ptr_array+i+1) = *(ptr_array+i);
                    *(ptr_array+i) = temp;
                }
            }
        }
        /***********************************************************************/
        break;

        case SELECTION_SORT:
        /****************** Implement Selection Sort Here **********************/
        for(int i = 0; i < arr_size - 1; i++)
        {
            int min_index = i;
            for(int j = i + 1; j < arr_size; j++)
            {
                if(*(ptr_array+j) < *(ptr_array+min_index))
                {
                    min_index = j;
                }
            }
            if(min_index != i)
            {
                int temp = *(ptr_array+i);
                *(ptr_array+i) = *(ptr_array+min_index);
                *(ptr_array+min_index) = temp;
            }
        }
        /***********************************************************************/
        break;

        case INSERTION_SORT:
        /**************** Implement Insertion Sort Here ************************/
        for(int i = 1; i < arr_size; i++)
        {
            int key = *(ptr_array+i);
            int j = i - 1;
            while(j >= 0 && *(ptr_array+j) > key)
            {
                *(ptr_array+j+1) = *(ptr_array+j);
                j--;
            }
            *(ptr_array+j+1) = key;
        }
        /***********************************************************************/
        break;

        case MERGE_SORT:
        /**************** Call Merge Sort Function Here ************************/
        merge_sort_array(ptr_array, arr_size);
        /***********************************************************************/
        break;

    case QUICK_SORT:
        /**************** Call Quick Sort Function Here ************************/
        quick_sort(ptr_array, 0, arr_size - 1);
        /***********************************************************************/
        break;
    }
}
void merge(int *ptr_array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = ptr_array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = ptr_array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ptr_array[k] = L[i];
            i++;
        }
        else
        {
            ptr_array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        ptr_array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ptr_array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *ptr_array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(ptr_array, left, mid);
        merge_sort(ptr_array, mid + 1, right);

        merge(ptr_array, left, mid, right);
    }
}

void merge_sort_array(int *ptr_array, int size)
{
    merge_sort(ptr_array, 0, size - 1);
}
int partition(int *ptr_array, int low, int high) {
    int pivot = ptr_array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (ptr_array[j] < pivot) {
            i++;
            int temp = ptr_array[i];
            ptr_array[i] = ptr_array[j];
            ptr_array[j] = temp;
        }
    }

    int temp = ptr_array[i + 1];
    ptr_array[i + 1] = ptr_array[high];
    ptr_array[high] = temp;

    return (i + 1);
}

void quick_sort(int *ptr_array, int low, int high) {
    if (low < high) {
        int pi = partition(ptr_array, low, high);

        quick_sort(ptr_array, low, pi - 1);
        quick_sort(ptr_array, pi + 1, high);
    }
}

/*Merge Sort: O(n*log(n))
Insertion Sort: O(n^2)
Selection Sort: O(n^2)
Bubble Sort: O(n^2)*/
