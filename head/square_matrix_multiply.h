#pragma once

#include "vector"
using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}