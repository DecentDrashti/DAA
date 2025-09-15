#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

// Find vertex with minimum distance
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index = -1;

    for (int v = 1; v <= V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print distance array
void printSolution(int dist[])
{
    printf("Vertex   Distance from Source (1)\n");
    for (int i = 1; i <= V; i++) {
        printf("\t%d \t\t %d\n", i, dist[i]);
    }
}

// Dijkstra’s algorithm (1-indexed)
void dijkstra(int graph[V+1][V+1], int src)
{
    int dist[V+1];
    int sptSet[V+1];

    // Initialize all distances as INFINITE
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;  // distance from source to itself = 0

    for (int count = 1; count <= V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 1; v <= V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

// Driver code
int main()
{
    // 1-indexed adjacency matrix
    int graph[V+1][V+1] = {
        { 0, 0, 0, 0, 0, 0, 0 }, // row 0 (unused)
        { 0, 0, 7, 9, 0, 0,14 }, // vertex 1
        { 0, 7, 0,10,15, 0, 0 }, // vertex 2
        { 0, 9,10, 0,11, 0, 2 }, // vertex 3
        { 0, 0,15,11, 0, 6, 0 }, // vertex 4
        { 0, 0, 0, 0, 6, 0, 9 }, // vertex 5
        { 0,14, 0, 2, 0, 9, 0 }  // vertex 6
    };

    dijkstra(graph, 1); // Source = 1

    return 0;
}
