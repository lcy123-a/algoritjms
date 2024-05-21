#pragma once
// 最长公共子序列长度
#include "vector"

using namespace std;

int lcs_lensth(vector<char> x, vector<char> y) {
    int m = x.size();
    int n = y.size();
    vector<char> x1 = {'0'};
    vector<char> y1 = {'0'};
    for (auto i : x) {
        x1.push_back(i);
    }
    for (auto j : y) {
        y1.push_back(j);
    }
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x1[i] == y1[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    return c[m][n];
}

/*
int main(int argc, char *argv[])
{
    vector<char> a = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    vector<char> b = {'B', 'D', 'C', 'A', 'B', 'A'};
    int c = lcs_lensth(a, b);
    cout << c << endl;
    system("pause");
    return 0;
}
*/