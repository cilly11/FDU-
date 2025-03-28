/*
连接木棍的最低费用
Description

现有一些零散的木棍，需要将其连接成一整根。

每次可以通过支付a+b的费用将两根长度分别为a和b的木棍连接成一根，不断执行此操作，直到将所有木棍连接成一根。

求将所有给定木棍以这种方式连接成一根木棍的最低费用。


Input
n个零散木棍的长度L,0<L<20,1<n<20,L∈Z,n∈Z

Output
合成一根木棍的最低费用


Sample Input 1 
[2,4,3]
Sample Output 1
14


Sample Input 2 
[1,8,3,5]
Sample Output 2
30


Sample Input 3 
[7, 3, 5, 2, 18]
Sample Output 3
67


Sample Input 4 
[20, 10, 17, 6, 6, 5, 20]
Sample Output 4
222
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 20

//哈夫曼编码思想，先把所有的放入到一个堆中，每次取最小的两个连接 
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;//左子结点
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;//交换
        minHeapify(heap, size, smallest);
    }
}

int extractMin(int heap[], int *size) {
    int min = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return min;
}

void insertHeap(int heap[], int *size, int value) {
    heap[(*size)++] = value;
    int i = *size - 1;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// 计算最小连接费用
int minCostToConnectSticks(int sticks[], int n) {
    int cost = 0;
    int size = 0;
    int heap[MAX_SIZE];

    // 将所有木棍插入最小堆中
    for (int i = 0; i < n; i++) {
        insertHeap(heap, &size, sticks[i]);
    }

    // 不断连接两根最小的木棍，直到剩下一根
    while (size > 1) {
        int first = extractMin(heap, &size);
        int second = extractMin(heap, &size);
        int newStick = first + second;
        cost += newStick;
        insertHeap(heap, &size, newStick);
    }

    return cost;
}

int main() {
    int sticks[MAX_SIZE];
    int n = 0;
    char input[100];


    fgets(input, sizeof(input), stdin);


    char *ptr = input;
    while (*ptr) {
        if (isdigit(*ptr)) {
            sticks[n] = strtol(ptr, &ptr, 10);  
            n++;
        } else {
            ptr++;
        }
    }

    int result = minCostToConnectSticks(sticks, n);
    printf("%d\n", result);  

    return 0;
}