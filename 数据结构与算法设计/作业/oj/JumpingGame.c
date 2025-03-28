/*
Description

给定一个下标从0开始的整数数组nums和一个整数k。

一开始玩家在下标0处。每一步，玩家最多可以往前跳k步，但不能跳出数组的边界。也就是说，可以从下标i跳到[i + 1， min(n - 1, i + k)]包含两个端点的任意位置。

玩家的目标是到达数组最后一个位置（下标为n - 1），得分为经过的所有数字之和。

请返回玩家能得到的最大得分。

（例如Sample1中取得最大得分的跳跃点为[1,-1,4,3]，Sample2中取得最大得分的跳跃点为[10,4,3]）


Input
输入整数数组nums和整数k。
Output
输出最大得分值。


Sample Input 1 
nums = [1,-1,-2,4,-7,3], k = 2
Sample Output 1
7

Sample Input 2 
nums = [10,-5,-2,4,0,3], k = 3
Sample Output 2
17

Sample Input 3 
nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Sample Output 3
0

Sample Input 4 
nums = [-3,9,-7,-9,-5,-2,1,-7,9,-9,3,4,10,5,1,-6], k = 2
Sample Output 4
22

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 滑动窗口最小值函数
void minSlidingWindow(int* nums, int size, int k) {
    int deque[1200]; // 双端队列，用来存储元素索引
    int front = 0, rear = -1; // 队列的前后指针
    int result[1200]; // 存储结果
    int result_count = 0;

    for (int i = 0; i < size; i++) {
        // 移除不在当前窗口范围内的元素（从前端移除）
        if (front <= rear && deque[front] <= i - k) {
            front++;
        }
        // 移除比当前元素大的元素（从后端移除）
        while (front <= rear && nums[deque[rear]] >= nums[i]) {
            rear--;
        }
        // 将当前元素索引添加到队列
        deque[++rear] = i;

        // 当窗口形成时，记录当前窗口的最小值
        if (i >= k - 1) {
            result[result_count++] = nums[deque[front]];
        }
    }

    // 输出结果
    printf("[");
    for (int i = 0; i < result_count; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", result[i]);
    }
    printf("]\n");
}

int main() {
     char input_str[1000];
    fgets(input_str, 1000, stdin);
    char nums_str[1000];

    char* nums_start = strstr(input_str, "nums = [");
    char* nums_end = strchr(input_str, ']');
    if (nums_start == NULL || nums_end == NULL) {
        printf("无效数组输入。\n");
        return 1;
    }
    nums_start += 8; //nums中的第一个元素 
    strncpy(nums_str, nums_start, nums_end - nums_start);//strncpy函数将nums_start复制到nums_str，共 nums_end - nums_start即n位 
    nums_str[nums_end - nums_start] = '\0'; //结束符，确保字符串结尾是null 
    for (int i = 0; nums_str[i]; i++) {
        if (nums_str[i] == ',') nums_str[i] = ' ';
    }

    int numArray[1000];
    int numCount = 0;
    char* token = strtok(nums_str, " ");
    while (token != NULL) {
        numArray[numCount++] = atoi(token);//atoi解析函数 
        token = strtok(NULL, " ");//替换为空格 
    }

    char* kvalue = strstr(input_str, "k =");
    if (kvalue == NULL) {
        printf("k未输入。\n");
        return 1;
    }
    int kValue = atoi(kvalue + 4);

    minSlidingWindow(numArray, numCount, kValue);

    return 0;
}