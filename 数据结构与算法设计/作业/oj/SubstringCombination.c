/*
子串组合
Description

给定一个字符串t和一个整数k，其中字符串t由n个小写字母组成。

我们定义一个字符串s的子串s[L,...,R]表示从字符串s的位置L到位置R所构成的一个新串。

请你构造一个有最小可能长度的字符串s，满足字符串s中存在k个位置i,满足s[i,...,i + n - 1] = t。

换句话说，你的任务是构造一个有最小可能长度的字符串s，满足s中恰好有k个子串是字符串t。


Input
输入总共两行：

第一行输入两个整数n和k，表示t的长度和需要k个子串。

第二行输入字符串t。

对于100%的数据，满足 1≤n,k≤50。


Output
输出满足条件的长度最小的s。

题目保证答案唯一。


Sample Input 1 
3 4
aba
Sample Output 1
ababababa


Sample Input 2 
3 2
cat
Sample Output 2
catcat


Sample Input 3 
1 50
q
Sample Output 3
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq


Sample Input 4 
8 3
abcaabca
Sample Output 4
abcaabcaabcaabca

*/

#include <stdio.h>
#include <string.h>

// KMP算法
void compute_prefix_function(char t[], int n, int pi[]) {
    pi[0] = 0;//存储前缀函数 
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && t[k] != t[i]) {
            k = pi[k - 1];
        }
        if (t[k] == t[i]) {
            k++;
        }
        pi[i] = k;
    }
}//回文字符前缀和后缀可重叠的最大长度 

int main() {
    int n, k;
    char t[51];
    
    scanf("%d %d", &n, &k);
    scanf("%s", t);

    int pi[51];
    compute_prefix_function(t, n, pi);
    
    // 重叠部分的长度，即最长的前缀也是后缀的部分
    int overlap = pi[n - 1];
    printf("%s", t);
    
    // 输出其余的k-1个t的拼接
    for (int i = 1; i < k; i++) {
        printf("%s", t + overlap);//后续只输出不重叠的部分，输出k-1次 
    }
    
    return 0;
}