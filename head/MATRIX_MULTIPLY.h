// 矩阵相乘
#include "assert.h"
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> a, vector<vector<int>> b) {
    int a_rows = a.size();
    int b_rows = b.size();
    int a_columns = a[0].size();
    int b_columns = b[0].size();
    if (a_columns != b_rows) {
        cout << "incompatible dimensions" << endl;
    } else {
        vector<vector<int>> c(a_rows, vector<int>(b_columns));
        for (int i = 0; i < a_rows; ++i) {
            for (int j = 0; j < b_columns; ++j) {
                c[i][j] = 0;
                for (int k = 0; k < a_columns; ++k) {   c[i][j] += a[i][k] * b[k][j]; }
            }
        }
        return c;
    }
}