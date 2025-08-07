// #include<stdio.h>
// #include<time.h>
// #include<limits.h>
// //krushkal's algorithm to find minimum spanning tree
// // This implementation assumes the edges are already sorted by weight
// #define V 7 // Number of vertices in the graph
// #define E 11
// struct Edge {
//     int source;
//     int dest;
//     int weight;
// };
// int find(int parent[], int i) {
//     if (parent[i] == i) return i;
//     return find(parent, parent[i]);
// }
// void unionSet(int parent[], int u, int v) {
//     parent[u] = v;
// }
// void krushkals(int V, int E, struct Edge edges[]) {
//     int parent[V];
//     int edge = 0;
//     struct Edge mst[V - 1];

//     // Initialize parent array
//     for (int i = 0; i < V; i++) {
//         parent[i] = i;
//     }

//     // Sort edges based on weight (not implemented here, assume sorted)
    
//     for (int i = 0; i < E; i++) {
//         int u = edges[i].source;
//         int v = edges[i].dest;

//         int ucomp = find(parent, u);
//         int vcomp = find(parent, v);

//         if (ucomp != vcomp) {
//             mst[edge] = edges[i];
//             unionSet(parent, ucomp, vcomp);
//             edge++;
//         }
//         if (edge == V - 1) break;
//     }

//     // Print the minimum spanning tree
//     printf("Minimum Spanning Tree edges:\n");
//     for (int i = 0; i < edge; i++) {
//         printf("%d -- %d == %d\n", mst[i].source, mst[i].dest, mst[i].weight);
//     }
// }

// void main(){
//     struct Edge mst[V - 1];
//     // Example edges for the graph
//     // Note: In a real implementation, edges should be sorted by weight before processing
//     // Here we assume edges are already sorted for simplicity
//     // Example edges for the graph
//     // Format: {source, destination, weight}
//     struct Edge edges[]={
//         {0,1,7},
//         {0,3,5},
//         {1,2,8},
//         {1,3,9},
//         {1,4,7},
//         {2,4,5},
//         {3,4,15},
//         {3,5,6},
//         {4,5,8},
//         {4,6,9},
//         {5,6,11}
//     };
//     krushkals(V,E,edges);
//     printf("Minimum Spanning Tree edges:\n");
//     for(int i=0;i<V-1;i++){
//         printf("%d -- %d == %d\n", mst[i].source, mst[i].dest, mst[i].weight);
//     }

// }
#include <stdio.h>

#define V 7// Number of vertices
#define E 11 // Number of edges

struct Edge {
    int source;
    int dest;    
    int weight;
};

// Find operation with path compression
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Union operation (no rank optimization here)
void unionSet(int parent[], int u, int v) {
    parent[u] = v;
}

// Kruskal's algorithm
void krushkals(int V, int E, struct Edge edges[], struct Edge mst[]) {
    int parent[V];
    int edgeCount = 0;

    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].source;
        int v = edges[i].dest;

        int uRoot = find(parent, u);
        int vRoot = find(parent, v);

        if (uRoot != vRoot) {
            mst[edgeCount++] = edges[i];
            unionSet(parent, uRoot, vRoot);
        }
        if(edge==V-1)break;
    }
}

int main() {
    struct Edge edges[] = {
        {0, 1, 7},
        {0, 3, 5},
        {1, 2, 8},
        {1, 3, 9},
        {1, 4, 7},
        {2, 4, 5},
        {3, 4, 15},
        {3, 5, 6},
        {4, 5, 8},
        {4, 6, 9},
        {5, 6, 11}
    };

    struct Edge mst[V - 1];

    krushkals(V, E, edges, mst);

    // Print the MST
    printf("Minimum Spanning Tree edges:\n");
    for (int i = 0; i < V - 1; i++) {
        printf("%d -- %d == %d\n", mst[i].source, mst[i].dest, mst[i].weight);
    }

    return 0;
}
