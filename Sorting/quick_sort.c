#include<stdio.h>
#include<time.h>

//quick sort function with pivot
int pivot(int arr[], int i, int j) 
{
    int k, l,pivot;
    pivot = arr[i];
    k = i;
    l = j+1;
    do{
        k++;
    }while( k < j && arr[k] <=pivot );//until che so undhi condition thay algorithm karta kem ke ee condition e loop break karvani che
    do{
        l--;
    }while( l > i && arr[l] > pivot );
    while(k<l) 
    {
        swap(&arr[k], &arr[l]); //swap the elements
        do {
            k++;
        } while (k < j && arr[k] <= pivot); 
       do{
            l--;
        } while (l > i && arr[l] > pivot); 
    }
    swap(&arr[i], &arr[l]);//swap the pivot with the last element
    return l; //return the index of the pivot quicksort ma apde last elemnet of array ne l-1 lesu so l pass karavu pade
    
}
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = pivot(arr, low, high);
        quickSort(arr, low, pivotIndex-1); // Recursively sort the left subarray
        quickSort(arr, pivotIndex+1 , high); // Recursively sort the right subarray
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[] = {10, 9, 8, 7, 6, 3, 5, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements   
    clock_t start, end;
    double time_taken;
    start = clock();
    quickSort(arr, 0, n - 1); // Call the quickSort function
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Calculate the time taken in milliseconds
    printf("Time taken to sort the array: %f ms\n", time_taken);
    printf("Sorted array: ");
    printArray(arr, n); // Print the sorted array

}