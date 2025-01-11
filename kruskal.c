#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];  // List of all edges
int parent[MAX];  // Union-Find parent array

// Function to find the root of a node
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to union two subsets
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Comparison function for sorting edges by weight
int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void kruskal(int n, int e) {
    int mstCost = 0, mstEdges = 0;

    // Initialize parent array for union-find
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), compare);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if adding this edge creates a cycle
        if (find(u) != find(v)) {
            printf("{%d, %d} = %d\n", u, v, weight);
            unionSets(u, v);  // Merge the two sets
            mstCost += weight;
            mstEdges++;

            // Stop if MST is complete (n-1 edges)
            if (mstEdges == n - 1)
                break;
        }
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", mstCost);
}

int main() {
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(n, e);

    return 0;
}
