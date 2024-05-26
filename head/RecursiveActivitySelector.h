#pragma once

#include <vector>

using namespace std;

/*
 * 递归版本
 */
void Recursive_Activity_Selector(vector<int>* A, int* s, int* f, int k, int n) {
 
	int m = k + 1;
	while (m <= n && s[m] < f[k]) {
		m++;
	}
 
	if (m <= n) {
		A->push_back(m);
		Recursive_Activity_Selector(A, s, f, m, n);
	}
}

/*
 * 迭代版本
 */
vector<int>* Greedy_Activity_Selector(int*s, int*f, int n) {
	vector<int>* A = new vector<int>;
 
	int k = 1;
	A->push_back(k);
 
	for (int m = 2; m <= n; m++) {
		if (s[m] >= f[k]) {
			A->push_back(m);
			k = m;
		}
	}
 
	return A;
}

// #include <vector>
// #include "iostream"

// #include "head/RecursiveActivitySelector.h"

// using namespace std;




// int main() {
    
//     int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
//     int f[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
//     vector<int>* times = Greedy_Activity_Selector(s, f, 11);
//     for (auto i = 0; i < times->size(); i++) {
//         cout << times->at(i) << " ";
//     }
//     system("pause");
// }


// int main() {
// 	int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
// 	int f[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
//     vector<int> times;
// 	Recursive_Activity_Selector(&times, s, f, 0, 11);
// 	for (auto i : times) {
// 		cout << i << " ";
// 	}
// 	system("pause");
// }