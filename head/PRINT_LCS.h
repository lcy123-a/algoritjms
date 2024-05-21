#pragma once
// 打印出最长公共子序列
#include "iostream"
#include "vector"

using namespace std;

vector<vector<char>> lcs_lensth(vector<char> x, vector<char> y) {
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
    vector<vector<char>> b(m + 1, vector<char>(n + 1, '0'));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x1[i] == y1[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 's';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '^';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<';
            }
        }
    }
    return b;
}

void print_lcs(vector<vector<char>> b, vector<char> X, int i, int j) {
    if (i == -1 || j == -1) {
        return;
    }
    if (b[i][j] == 's') {
        print_lcs(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == '^') {
        print_lcs(b, X, i - 1, j);
    } else {
        print_lcs(b, X, i, j - 1);
    }
}