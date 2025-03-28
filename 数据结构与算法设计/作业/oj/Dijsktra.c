/*
Dijsktra算法求解单源最短路径
Description

给定一个 n 个点，m 条有向边的带非负权图，请你计算从起点 s 出发，到每个点的距离。

数据保证能从 s 出发到任意点。


Input
第一行为三个正整数 n, m, s。第二行起 m 行，每行三个非负整数 u, v, w，表示从 u 到 v 有一条权值为 w 的有向边。

对于100%的数据：
1≤n≤1000；
1≤m≤1000；
1≤s,u,v≤n；
0≤w≤999。


Output
输出一行 n 个空格分隔的非负整数，表示起点 s 到每个点的距离。


Sample Input 1 
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

Sample Output 1
0 2 4 3


*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_N 1001  // 最大点数
#define MAX_M 10001 // 最大边数
#define MAX_S 1000 
#define INF INT_MAX // 无穷大


int graph[MAX_N][MAX_N]; // 从节点i到节点j的权重 ，无边则为INF

// Dijkstra 算法求单源最短路径
void dijkstra(int n, int s) {
    int dist[MAX_N]; // 起点s到各个点的最短距离 
    int visited[MAX_N] = {0}; 
    int i, u, v;

    for (i = 1; i <= n; i++) {
        dist[i] = INF; // 初始化 
    }
    dist[s] = 0; // s到s距离 

    for (i = 1; i <= n; i++) {
        int minDist = INF; 
		u = -1;
        for (v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];//更新最短距离 
                u = v;
            }
        }

        if (u == -1) break; // 如果所有点都已访问过，则退出

        visited[u] = 1; // 已访问

        // 更新与 u 连接的所有未访问的邻居的最短距离
        for (v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, m, s, u, v, w;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF; // 初始化为无穷大
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // 有向边，从 u 到 v 权值为 w
    }
    dijkstra(n, s);
    return 0;
}
