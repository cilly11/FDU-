/*
矩阵的最大矩形面积
Description

给定一个 01 矩阵，找出其中包含的最大矩形（由1形成）的面积，矩形中的 1 必须全部连续且没有 0


Input
第一行输入为矩阵的尺寸，第二行开始描述输入m×n的 0 1 矩阵 中间用空格隔开

样例：

4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output
输出为最大矩形的面积，样例中最大矩形为：


1 1 1

1 1 1

故最大面积为：

6



Sample Input 1 

4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Sample Output 1

6
*/


#include <stdio.h>

#define MAX_COLS 100

//height高度（宽），n列的矩阵 
int largestRectangleArea(int *heights, int n) {
    int stack[MAX_COLS];
    int top = -1;
    int maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        
        while (top != -1 && heights[stack[top]] > currentHeight) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        stack[++top] = i;
    }
    
    return maxArea;
}


int maximalRectangle(int matrix[][MAX_COLS], int rows, int cols) {
    int heights[MAX_COLS] = {0}; // 用于存储每列的高度
    int maxArea = 0;
    
    // 对每一行处理
    for (int i = 0; i < rows; i++) {
        // 对每一列处理，遇到0则将该列高度归零
        for (int j = 0; j < cols; j++) {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }
        // 计算当前行的直方图最大矩形面积
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    return maxArea;
}

int main() {
    int rows, cols;
    
    // 输入矩阵的行数和列数
    scanf("%d %d", &rows, &cols);
    
    int matrix[MAX_COLS][MAX_COLS];
    
    // 输入矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // 计算并输出最大矩形面积
    int maxArea = maximalRectangle(matrix, rows, cols);
    printf("%d\n", maxArea);
    
    return 0;
}