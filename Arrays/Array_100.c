#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100
#define P 1000
#define K 10000
#define L 100000
// clock_t start,end;
// double time_taken;

void write_best_case()
{
    FILE *f=fopen("best_case_100.txt","w");
    for(int i=1;i<=N;i++)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_best_case_1000()
{
    FILE *f=fopen("best_case_1000.txt","w");
    for(int i=1;i<=P;i++)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_best_case_10000()
{
    FILE *f=fopen("best_case_10000.txt","w");
    for(int i=1;i<=K;i++)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_best_case_100000()
{
    FILE *f=fopen("best_case_100000.txt","w");
    for(int i=1;i<=L;i++)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_worst_case()
{
    FILE *f=fopen("worst_case_100.txt","w");
    for(int i=N;i>=1;i--)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_worst_case_1000()
{
    FILE *f=fopen("worst_case_1000.txt","w");
    for(int i=P;i>=1;i--)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_worst_case_10000()
{
    FILE *f=fopen("worst_case_10000.txt","w");
    for(int i=K;i>=1;i--)
        fprintf(f, "%d ",i);
    fclose(f);
}

void write_worst_case_100000()
{
    FILE *f=fopen("worst_case_100000.txt","w");
    for(int i=L;i>=1;i--)
        fprintf(f, "%d ",i);
    fclose(f);
}

//this algorithm may repeat the file
// void write_average_case()
// {
//     //random generating number
//     int arr[N];
//     srand(time(0));
//     for(int i=0;i<N;i++)
//     {
//         arr[i] = rand() % 100 + 1; // Random numbers between 1 and 100
    
//     }
//     // Writing to file
//     FILE *f=fopen("average_case_100.txt","w");

//     for(int i=1;i<=N;i++)
//         fprintf(f, "%d ",arr[i-1]);
//     fclose(f);
// }


//this algorithm wont repeat any number in file
void write_average_case()
{
    int arr[N];
    for(int i=1;i<=N;i++)
        arr[i-1]=i;
    
    //shuffle array
    srand(time(NULL));
    for(int i=N-1;i>0;i--)
    {
        int j=rand()%(i+1);
        //swap
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    FILE *f=fopen("average_case_100.txt","w");

    for(int i=1;i<=N;i++)
        fprintf(f, "%d ",arr[i]);
    fclose(f);

}

void write_average_case_1000()
{
    int arr[P];
    for(int i=1;i<=P;i++)
        arr[i-1]=i;
    
    //shuffle array
    srand(time(NULL));
    for(int i=P-1;i>0;i--)
    {
        int j=rand()%(i+1);
        //swap
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    FILE *f=fopen("average_case_1000.txt","w");

    for(int i=1;i<=P;i++)
        fprintf(f, "%d ",arr[i]);
    fclose(f);

}

void write_average_case_10000()
{
    int arr[K];
    for(int i=1;i<=K;i++)
        arr[i-1]=i;
    
    //shuffle array
    srand(time(NULL));
    for(int i=K-1;i>0;i--)
    {
        int j=rand()%(i+1);
        //swap
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    FILE *f=fopen("average_case_10000.txt","w");

    for(int i=1;i<=K;i++)
        fprintf(f, "%d ",arr[i]);
    fclose(f);

}

void write_average_case_100000()
{
    int arr[L];
    for(int i=1;i<=L;i++)
        arr[i-1]=i;
    
    //shuffle array
    srand(time(NULL));
    for(int i=L-1;i>0;i--)
    {
        int j=rand()%(i+1);
        //swap
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    FILE *f=fopen("average_case_100000.txt","w");

    for(int i=1;i<=L;i++)
        fprintf(f, "%d ",arr[i]);
    fclose(f);

}

void main()
{
    //start=clock();
    write_best_case_100000();
    write_worst_case_100000();
    write_average_case_100000();
    //end=clock();
    //time_taken=((double)(end-start))/CLOCKS_PER_SEC*1000;
    //printf("average case of 100000 time %f ms\n",time_taken);
    // write_worst_case();
    // write_average_case();
    printf("Successfully created file best_case_100.txt,worst_case_100.txt,avg_case_100.txt for best case ,worst case,average case respectively!!");
}