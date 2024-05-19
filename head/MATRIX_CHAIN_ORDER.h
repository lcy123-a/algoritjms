// 计划最优代价
#include "iostream"

using namespace std;


/* 计算n元矩阵链p的最优代价
 * 动态规划的每一步结果储存在 ans与 divide中 */
void MatrixChainOrder(int p[], int n) {
    int ans[n][n];
    int divide[n + 1][n + 1];
    /* 初始化divide数组 */
    for (int i = 1; i <= n; i++)
        divide[i][i] = i;
    /* 矩阵链长度为2到n */
    for (int l = 2; l <= n; l++) {
        /* 讨论长度为l的矩阵链A[i..j] */
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            ans[i][j] = INT_MAX;
            /* 在特定区间内：依次讨论每一个分割点d，将矩阵链A[i..j]分成A[i..d]和 A[d+1..j] */
            for (int temp, d = divide[i][j - 1]; d <= divide[i + 1][j]; d++) {
                temp = ans[i][d] + ans[d + 1][j] + p[i - 1] * p[d] * p[j];
                /* 记录下矩阵链A[i..j]最小的情况 */
                if (temp < ans[i][j]) {
                    ans[i][j] = temp;
                    divide[i][j] = d;
                }
            }
        }
    }
    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (auto& i : divide) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}