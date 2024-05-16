#pragma once

#include "iostream"
#include "vector"

using namespace std;

// 钢条切割
//  vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//    int n = 4;

int cut_rod(vector<int> p, int n) {     // 自顶向下的递归实现
    if (n == 0) {
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        q = max(q, p[i] + cut_rod(p, n - i));
    }
    return q;
}

int memoized_cur_rod_aux(vector<int> p, int n, vector<int> r) {     // 带备忘录的自顶向下法
    if (r[n] >= 0) {
        return r[n];
    }
    int q = 0;
    if (n == 0) {
        q = 0;
    } else {
        q = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            q = max(q, p[i] + memoized_cur_rod_aux(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(vector<int> p, int n) {
    vector<int> r(n + 1, INT_MIN);
    return memoized_cur_rod_aux(p, n, r);
}

int bottom_up_cut_rod(vector<int> p, int n) {       // 自底向上
    vector<int> r(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int q = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            q = max(q, p[j] + r[i - j]);
        }
        r[i] = q;
    }
    return r[n];
}

void extended_bottom_up_cut_rod(vector<int> p, int n) {
    vector<int> r(n + 1, 0);
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int q = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            if (q < p[j] + r[i - j]) {
                q = p[j] + r[i - j];
                s[i] = j;
            }
            r[i] = q;
        }
    }
    for (auto& i : r) {
        cout << i << " ";
    }
    cout << endl;
    for (auto& i : s) {
        cout << i << " ";
    }
    cout << endl;
}