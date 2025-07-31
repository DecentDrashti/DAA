#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void insertionSort(int arr[],int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
        
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

int main()
{
    int arr[N];
    clock_t start,end;
    double time_taken;

    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/best_case_100000.txt",arr,N))
    {
        start = clock();
        insertionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Best Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/worst_case_100000.txt",arr,N))
    {
        start = clock();
        insertionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Worst Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/average_case_100000.txt",arr,N))
    {
        start = clock();
        insertionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Average Case Time:%f ms\n",time_taken);
    }
}