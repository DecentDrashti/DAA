#include<stdio.h>
#include<time.h>
#include<limits.h>
//prims algorithm to find minimum spanning tree
#define N 5

int main(){
    int graph[N][N]={
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    int selected[N]={0};
    selected[0]=1; // Start with the first vertex
    int edges=0;
    printf("Edge :\tWeight\n");
    int i ,j;

    int total = 0; // To keep track of the total weight of the MST
    
    while(edges < N-1){
        int min = INT_MAX;
        int x = 0, y = 0;
        for(i=0; i<N; i++){
            if(selected[i]==1){
                for(j=0; j<N; j++){
                    if(selected[j]==0 && graph[i][j]!=0){
                        if(graph[i][j] < min){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

    
    printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1; // Mark the selected vertex
        edges++;
        total += min;
        
       
    }
    printf("Total weight of the Minimum Spanning Tree: %d\n", total);
     
        
}