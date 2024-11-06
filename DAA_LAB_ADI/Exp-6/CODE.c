#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void dijkstra(int graph[][5], int source) {
    int distance[5];
    int visited[5];

    for (int i = 0; i < 5; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int i = 0; i < 5; i++) {
        int min_distance = INF;
        int min_index = -1;

        for (int j = 0; j < 5; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        for (int j = 0; j < 5; j++) {
            if (!visited[j] && graph[min_index][j] != 0 && distance[min_index] + graph[min_index][j] < distance[j]) {
                distance[j] = distance[min_index] + graph[min_index][j];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < 5; i++) {
        printf("%d: %d\n", i, distance[i]);
    }
}

void bellman_ford(int graph[][5], int source) {
    int distance[5];

    for (int i = 0; i < 5; i++) {
        distance[i] = INF;
    }

    distance[source] = 0;

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (graph[j][k] != 0 && distance[j] + graph[j][k] < distance[k]) {
                    distance[k] = distance[j] + graph[j][k];
                }
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < 5; i++) {
        printf("%d: %d\n", i, distance[i]);
    }
}

int main() {
    int graph[][5] = {
        {0, 4, 0, 0, 0},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);
    bellman_ford(graph, 0);

    return 0;
}