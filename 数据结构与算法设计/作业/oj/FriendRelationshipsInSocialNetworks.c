/*
社交网络中的朋友关系
Description

在一个社交网络中，每个用户都有一个唯一的 ID。用户之间可以通过“朋友”关系建立联系。如果 A 和 B 是朋友，且 B 和 C 是朋友，那么 A 和 C 也可以视为间接朋友。现在给定一些用户之间的朋友关系，你需要处理以下两种操作：

建立朋友关系：对于某一对用户 A 和 B，表示 A 和 B 成为朋友（可以视为他们属于同一个社交圈）。
查询是否在同一个社交圈：给定一对用户 A 和 B，判断 A 和 B 是否在同一个社交圈内。

Input
第一行一个整数n，表示社交网络中有n个用户，ID 为0到n-1。
第二行一个整数q，表示接下来有q个操作。
n<10 q<10
接下来q行，每行一个操作。操作有两种：
"1 A B"：表示 A 和 B 建立朋友关系。
"2 A B"：查询 A 和 B 是否在同一个社交圈。

Output
对于每个查询操作，输出YES或NO，表示 A 和 B 是否在同一个社交圈内。

Sample Input 1 

5 6
1 0 1
1 1 2
2 0 2
1 3 4
2 0 4
2 3 4



Sample Output 1

YES
NO
YES

*/


#include <stdio.h>

#define MAX_USERS 10
#define MAX_QUERIES 10

// 并查集结构
int parent[MAX_USERS];

// 查找根节点，同时进行路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootA] = rootB;  // 将一个根连接到另一个根，实现社交圈的合并 ，代表节点相同，说明在一个社交圈 
    }
}

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // 每个节点的初始根节点是自己
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    initialize(n);
    int operation[q];
	int a[q],b[q]; 
	char results[MAX_QUERIES][4]; 
    int result_count = 0;
	for (int i=0;i<q;i++){
		scanf("%d %d %d", &operation[i], &a[i], &b[i]);
	}
    for (int i = 0; i < q; i++) {
//1用来建立关系，2用来判断 
        if (operation[i] == 1) {
            union_set(a[i], b[i]);
        } else if (operation[i] == 2) {
            if (find(a[i]) == find(b[i])) {
                sprintf(results[result_count++],"YES");
            } else {
                sprintf(results[result_count++],"NO");
            }
        }
    }
    for (int i = 0; i < result_count; i++) {
    printf("%s\n", results[i]);
    }
    return 0;
}