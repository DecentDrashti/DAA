#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 100000

int heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest= left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}
int heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
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

//     int arr[]={10,9,8,7,6,4,5,2,1,3};
//     heapSort(arr,10);
//    for(int i=0;i<10;i++){
//         printf("arr[%d]= %d",i,arr[i]);
//    } 
    
    clock_t start,end;
    double time_taken;

    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/best_case_100000.txt",arr,N))
    {
        start = clock();
        heapSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Best Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/worst_case_100000.txt",arr,N))
    {
        start = clock();
        heapSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Worst Case Time:%f ms\n",time_taken);
    }
    if(readArrayFromFile("C:/Users/dr_dr/OneDrive/Desktop/B.Tech CSE/DAA/Arrays/average_case_100000.txt",arr,N))
    {
        start = clock();
        heapSort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("Average Case Time:%f ms\n",time_taken);
    }
}