#include<stdio.h>
//krushkals algorithm 
int find(int parent[],int i){
    if(parent[i]==i)return i;
    return find(parent,parent[i]);
}
void unionSet(int parent[],int u,int v)
{
    parent[u]=v;
}
void krushkals(int V ,int E,struct Edge edges[]){
    int parent[V];
    int edge=0;
    struct Edge mst[V-1];
    for(int i=0;i<V;i++){
        int u=edges[i].source;
        int v=edges[i].dest;

        int ucomp=find(parent,u);
        int vcomp=find(parent,v);

        if(ucomp!=vcomp){
            mst[edge]=edges[i];
            unionSet(parent,ucomp,vcomp);
            edge++;
        }
        if(edge==V-1)break;
    }
}

void main(){
    struct Edge edges[]={
        {0,1,7},
        {0,3,5},
        {1,2,8},
        {1,3,9},
        {1,4,7},
        {2,4,5},
        {3,4,15},
        {3,5,6},
        {4,5,8},
        {4,6,9},
        {5,6,11}
    };
    krushkals(V,E,edges);
}