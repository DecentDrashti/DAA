#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
int selectionSort(int arr[],int n)
{
    int i,j,min_index,temp;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for (int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
        
    }
    
    return 1;
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
//     selectionSort(arr,10);
//    for(int i=0;i<10;i++){
//         printf("arr[%d]= %d",i,arr[i]);
//    }
    
    
    clock_t start,end;
    double time_taken;

    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/best_case_100000.txt",arr,N))
    {
        start = clock();
        selectionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Best Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/worst_case_100000.txt",arr,N))
    {
        start = clock();
        selectionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Worst Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/average_case_100000.txt",arr,N))
    {
        start = clock();
        selectionSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Average Case Time:%f ms\n",time_taken);
    }
}