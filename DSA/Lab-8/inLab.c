#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 131072   /// 16, 128, 1024, etc

#define BUBBLE_SORT     1
#define SELECTION_SORT  2
#define INSERTION_SORT  3
#define MERGE_SORT      4

void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);
void merge_sort_array(int * ptr_array, int size);

int main()
{
    srand((unsigned int)time(NULL));    /// Random number generator seeded with value of time

    /** Initialize an Integer Array and initialize it with random numbers between 0-999 **/
    int my_array[ARRAY_SIZE];

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        my_array[i] = rand()%1000;
    }
    /*************************************************************************************/

    /// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

    // Making menu driven program
    int sort_type;
    printf("Choose the sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter the number corresponding to the sorting method: ");
    scanf("%d", &sort_type);

    switch (sort_type)
    {
    case 1:
        printf("Bubble Sort\n");
        sort_array(my_array,ARRAY_SIZE,BUBBLE_SORT);
        break;
    
    case 2:
        printf("Selection Sort\n");
        sort_array(my_array,ARRAY_SIZE,SELECTION_SORT);
        break;
    
    case 3:
        printf("Insertion Sort\n");
        sort_array(my_array,ARRAY_SIZE,INSERTION_SORT);
        break;

    case 4:
        printf("Merge Sort\n");
        sort_array(my_array,ARRAY_SIZE,MERGE_SORT);
        break;
    
    default:
        printf("Invalid choice\n");
        break;
    }

	clock_t end = clock();

	print_array(my_array, ARRAY_SIZE);
	/// calculate elapsed time by finding difference (end - begin) and
	/// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n\nTime elpased is %f seconds\n", time_spent);

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
         for(int k = arr_size; k>0; k--)    /// Outer loop moves the partition between the
         {                                  /// sorted and un-sorted sub-arrays.
            for(int i=0; i<k-1; i++)
            {
                if(*(ptr_array+i)>*(ptr_array+i+1)) /// If item on the left is greater than the one on the right
                {
                    int temp = *(ptr_array+i+1);    /// Swap them.
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
            int temp = *(ptr_array+i);
            *(ptr_array+i) = *(ptr_array+min_index);
            *(ptr_array+min_index) = temp;
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
                j = j - 1;
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
    }


}

void merge_sort_array(int * ptr_array, int size)
{
    /*** Complete this function ***/
    if(size > 1)
    {
        int mid = size/2;
        int * left = ptr_array;
        int * right = ptr_array + mid;

        int left_size = mid;
        int right_size = size - mid;

        merge_sort_array(left, left_size);
        merge_sort_array(right, right_size);

        int i = 0, j = 0, k = 0;

        while(i < left_size && j < right_size)
        {
            if(left[i] < right[j])
            {
                ptr_array[k] = left[i];
                i++;
            }
            else
            {
                ptr_array[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < left_size)
        {
            ptr_array[k] = left[i];
            i++;
            k++;
        }

        while(j < right_size)
        {
            ptr_array[k] = right[j];
            j++;
            k++;
        }
    }

}
