#include<stdio.h>
#include<time.h>

#define N 100
//binary search function
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int mid;
    while(left<=right) {
        mid = (left + right) / 2; // To avoid overflow
        if(arr[mid] == target) {
            return mid; 
        }
        else if(arr[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1; 
        }
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
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[N];
    clock_t start,end;
    double time_taken;
    int Target;
    printf("Enter the element to search: ");
    scanf("%d", &Target);
    //int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/best_case_100.txt",arr,N))
    {
        start = clock();
        int result = binarySearch(arr, N, Target);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 100;
        printf("Best Case Time: %f ms\n", time_taken);
    
    if(result != -1) {
        printf("Element found at index: %d\n", result);
    }else{
        printf("Element is not found");
    }
}
}