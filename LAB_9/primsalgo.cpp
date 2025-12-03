#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int selected[MAX] = {0};
    int edgeCount = 0;
    int totalWeight = 0;

    selected[0] = 1;

    printf("\nEdges in MST:\n");

    while (edgeCount < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        selected[v] = 1;
        edgeCount++;
        totalWeight += min;

        printf("%d -- %d  (weight %d)\n", u, v, min);
    }

    printf("\nTotal weight of MST = %d\n", totalWeight);

    return 0;
}
