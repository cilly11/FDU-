/*
Floyd算法求解全图最短路径
Description

给出一张由 n 个点 m 条边组成的无向图。

求出所有点对 (i,j) 之间的最短路径。


Input
第一行为两个整数 n和m，分别代表点的个数和边的条数。

接下来 m 行，每行三个整数 u,v,w，代表 u,v 之间存在一条边权为 w 的边。

对于100%的数据：

1≤n≤100；

1≤m≤4500；

1≤u,v≤n；

0≤w≤999。


Output
输出 n 行，每行 n 个整数，用n个空格隔开（行末有空格）。

第 i 行的第 j 个整数代表从 i 到 j 的最短路径长度。（如果不连通， i 到 j 不连通，请输出2147483647）


Sample Input 1 
4 4
1 2 1
2 3 1
3 4 1
4 1 1

Sample Output 1
0 1 2 1
1 0 1 2
2 1 0 1
1 2 1 0

*/

#include <stdio.h>
#include <limits.h>

#define MAX_N 101      // 最大节点数
#define INF INT_MAX    // 无穷大

// Floyd-Warshall算法
void floyd(int n, int dist[MAX_N][MAX_N]) {
    int k, i, j;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; //途径k节点的路径小于直接到达的路径，则进行更新 
                }
            }
        }
    }
}

int main() {
    int n, m, u, v, w;
    int dist[MAX_N][MAX_N]; // 输出的矩阵存储的值 
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;  // i 到 i 的距离是 0
            } else {
                dist[i][j] = INF; 
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;  // 由于是无向图，所以需要更新两个方向 
        dist[v][u] = w;  
    }
    floyd(n, dist);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                printf("2147483647 "); // 如果不可到达，输出2147483647
            } else {
                printf("%d ", dist[i][j]); // 输出最短路径
            }
        }
        printf("\n");
    }

    return 0;
}