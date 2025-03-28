/*
网络服务器任务队列
Description

在一台高并发的网络服务器上，所有的请求任务通过一个任务队列来管理。服务器的任务处理器一次只能处理一个请求，而请求会源源不断地到达。为了防止任务过多导致服务器崩溃，服务器的任务队列是一个容量为n的循环队列。每当任务队列满时，服务器将拒绝新的任务，并提示“Queue Full”。当任务队列为空时，服务器将无法处理任务，并提示“Queue Empty”。
你需要实现一个任务队列，支持如下操作：

add_task(x)：添加一个任务编号为x的请求进入队列。如果队列已满，输出“Queue Full”并不添加任务。
process_task()：处理队列中的一个任务（从队列头部取出）。如果队列为空，输出“Queue Empty”。
peek_task()：查看队列中的第一个任务编号。如果队列为空，输出“Queue Empty”。
queue_size()：返回队列中的任务数量。
isFull()：判断队列是否已满。
isEmpty()：判断队列是否为空。

Input
第一行输入一个正整数n（1 ≤ n ≤ 1000），表示任务队列的最大容量。
接下来每行输入一个操作，直到输入end结束。操作包括：
add_task x，表示添加任务编号为x的请求。
process_task，表示处理队列中的一个任务。
peek_task，查看当前任务队列中的第一个任务编号。
queue_size，返回当前队列的任务数量。
isFull，判断队列是否满。
isEmpty，判断队列是否为空。

Output
每当执行process_task()或peek_task()时，若队列为空，输出“Queue Empty”；否则输出对应的任务编号。
每当执行add_task(x)时，若队列满了，输出“Queue Full”。
每当执行queue_size()时，输出当前队列中的任务数量。
每当执行isFull()或isEmpty()时，输出true或false。

Sample Input 1 
5
add_task 101
add_task 102
add_task 103
queue_size
peek_task
process_task
peek_task
process_task
add_task 104
add_task 105
add_task 106
add_task 107
add_task 108
isFull
process_task
process_task
add_task 109
process_task
end

Sample Output 1
3
101
101
102
102
Queue Full
true
103
104
105

*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 1001
#define OUTPUT_BUFFER_SIZE 10000

typedef struct {
    int tasks[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} TaskQueue;


void initQueue(TaskQueue *queue, int capacity) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
}

// 是否为空
bool isEmpty(TaskQueue *queue) {
    return queue->size == 0;
}

//是否已满
bool isFull(TaskQueue *queue) {
    return queue->size == queue->capacity;
}

//添加一个任务编号为x的请求进入队列，如果队列已满，输出“Queue Full”并不添加任务。 
void add_task(TaskQueue *queue, int x, char *output) {
    if (isFull(queue)) {
        strcat(output, "Queue Full\n");
    } else {
        queue->tasks[queue->rear] = x;
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->size++;
    }
}

// 处理队列中的一个任务（从队列头部取出）
void process_task(TaskQueue *queue, char *output) {
    if (isEmpty(queue)) {
        strcat(output, "Queue Empty\n");
    } else {
        char buffer[50];//缓存区，使得最后结果能以整体形式输出 
        sprintf(buffer, "%d\n", queue->tasks[queue->front]);
        strcat(output, buffer);
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
    }
}

// 查看队列中的第一个任务
void peek_task(TaskQueue *queue, char *output) {
    if (isEmpty(queue)) {
        strcat(output, "Queue Empty\n");
    } else {
        char buffer[50];
        sprintf(buffer, "%d\n", queue->tasks[queue->front]);
        strcat(output, buffer);
    }
}

// 返回当前队列中的任务数量
void queue_size(TaskQueue *queue, char *output) {
    char buffer[50];
    sprintf(buffer, "%d\n", queue->size);
    strcat(output, buffer);
}

int main() {
    int n;
    scanf("%d", &n); // 读取队列的容量

    TaskQueue queue;
    initQueue(&queue, n);

    char command[50]; // 用于存储命令行
    char output[OUTPUT_BUFFER_SIZE] = ""; 
    char commandType[20]; // 存储命令类型
    int x;


    while (1) {
        scanf(" %[^\n]", command); //整行读取 

        sscanf(command, "%s", commandType); 
    
 //使用strcmp函数，比较两个字符串，如果相等返回0，前小于后返回负数，前大于后返回正数 
        if (strcmp(commandType, "add_task") == 0) {
            sscanf(command, "%*s %d", &x); 
            add_task(&queue, x, output);
        } else if (strcmp(commandType, "process_task") == 0) {
            process_task(&queue, output);
        } else if (strcmp(commandType, "peek_task") == 0) {
            peek_task(&queue, output);
        } else if (strcmp(commandType, "queue_size") == 0) {
            queue_size(&queue, output);
        } else if (strcmp(commandType, "isFull") == 0) {
            strcat(output, isFull(&queue) ? "true\n" : "false\n");
        } else if (strcmp(commandType, "isEmpty") == 0) {
            strcat(output, isEmpty(&queue) ? "true\n" : "false\n");
        } else if (strcmp(commandType, "end") == 0) {
            break;
        }
    }


    printf("%s", output);//整体形式输出

    return 0;
}
