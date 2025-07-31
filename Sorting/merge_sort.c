#include<stdio.h>
#include<time.h>

#define N 100
// Function to mergesort two halves of an array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // To avoid overflow
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return arr[left]; // Return the first element of the sorted array
}

//merge function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n2], R[n1];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}
int readArrayFromFile(const char *filename,int arr[],int n)
{
    FILE *f = fopen(filename,"r");
    if(!f)
    {
        printf("cannot open file %s\n",filename);
        return 0;
    }
    for(int i = 0; i < n; i++)
        fscanf(f,"%d",&arr[i]);
    fclose(f);
    return 1;
}

void main() {
    int arr[N];
    printf("Merge Sort Example\n");
//     int arr[7]={38, 27, 43, 3, 9, 82, 10}; // Example array for testing
//     printf("Original array: \n");
//    for (int i=0; i < 7; i++) {
//         printf("%d ", arr[i]);
//     }

    clock_t start, end;
    double time_taken;
//     mergeSort(arr, 0, 6); // Sorting the example array
//     printf("\nSorted array: \n");
//    for (int i=0; i < 7; i++) {
//         printf("%d ", arr[i]);
//     }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/best_case_100.txt", arr, N)) {
        start = clock();
        mergeSort(arr, 0, N-1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
        printf("Array has been sorted\n");
    }

    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/worst_case_100.txt", arr, N)) {
        start = clock();
        mergeSort(arr, 0, N-1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
        printf("Array has been sorted\n");
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/average_case_100.txt", arr, N)) {
        start = clock();
        mergeSort(arr, 0, N-1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
        printArray(arr);
    }
}
      