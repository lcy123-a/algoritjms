#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define N 11
 
/*
 * 活动的结构体，有一个id，一个开始时间，一个结束时间
 */
struct activity {
	int id;
	int start_time;
	int end_time;
};
 
//0初始化
int s[N + 2][N + 2] = { 0 };
 
/*
 * 记录Sij能达到最佳的一个分段活动的下标k。贪心算法这里是在以结束时间升序排列之后，取A1，而动态规划追求全局最优，所以要遍历所有可能的k取值，然后
 * 去需找一个能达到最优的解，这里的k并不代表第一个节点的分解方法
 */
 
/*这里数据取N+2的原因，是因为要插入一个开始和结束时间都是0的0节点进去，所以本来是11个节点，就变成了11+1个节点，
 *
 * 插入0节点的原因是因为当A[i].start_time=0的时候还是需要跟A[i-1].end_time进行比较，否则没法确定边界，所以添加一个0节点
 * 然后又由于i=N的时候，还需要考虑A[i].end_time
 * 所以要跟A[i+1].start_time比较，所以要取到i+1=N+1，所以数据下标的范围要是0~N+2，这里添加的第N+1节点为了让其永远也选不到，所以
 * 让它的开始时间和结束时间都是最大0x7fffffff，如果在java里，可能会直接取Integer.MAX_VALUE
 */
int cut_point[N + 2][N + 2] = { 0 };
 
activity A[N + 2];
 
/*
 * 动态规划法解活动问题
 */
void Dynamic_Programme() {
 
	int step; //步长，为j-i，的差值
	int i, j, k;
	int result;
 
	/*
	 * 因为Sij代表的是在活动Ai结束之后 和 Aj开始之前的 活动集，所以，当j<=i+1的时候，明显Sij为空，所以这里step从2开始循环
	 */
 
	for (step = 2; step <= N + 1; step++) {
 
		//在每个步长下，对所有的i进行遍历
		for (i = 0; i <= N; i++) {
			j = step + i;
 
			//这里如果j比N+1大了，就不考虑了，因为数组只到N+1的下标
			if (j <= N + 1) {
 
				//根据Sij的定义，肯定Ai和Aj两个活动之间需要有间隔，否则Sij就为空了，这里由于i=N的时候，还需要考虑A[i].end_time
				//所以要跟A[i+1].start_time比较，所以要取到i+1=N+1，所以数据下标的范围要是0~N+2
				if (A[i].end_time <= A[j].start_time) {
 
					//在符合条件的k中，这里k在i+1和j之间：[i+1,j)；去寻找能使得问题最优的k，也就是使得Sij包含最多活动的解
					for (k = i + 1; k < j; k++) {
 
						//这里k也需要做判断，需要于Ai和Aj兼容
						if (A[k].end_time > A[j].start_time
								|| A[k].start_time < A[i].end_time) {
							continue;
						}
 
						//根据【算导第三版16.2公式】
						result = s[i][k] + s[k][j] + 1;
						if (result > s[i][j]) {
							s[i][j] = result; //记录当前分割方式包含的最多活动数
							cut_point[i][j] = k; //并且记录当时的分割点下标
						}
					}
				}
			}
		}
	}
	cout << "最大兼容活动集包含的活动个数为：" << s[0][N + 1] << endl;//返回Sij中最大兼容活动集包含的活动个数
}
//打印具体是哪几个活动在Sij中
void Print(int start, int end) {
 
	int k = cut_point[start][end];
 
	//以为k=0的情况是Sij中没有合适的活动的情况，不是分割点，所以略去
	if (k != 0) {
		Print(start, k);
		cout << k << ' ';
		Print(k, end);
 
	}
 
}
 
bool cmp(activity a, activity b) {
	return a.end_time < b.end_time;
}
 

// #include "iostream"

// #include "head/DynamicActivitySelector.h"

// using namespace std;

// int main() {
 
// 	int i = 0;
// //让A[0]为0值
// 	A[i].start_time = 0;
// 	A[i].end_time = 0;
// 	A[i].id = 0;
 
// 	A[1].start_time = 1;
// 	A[1].end_time = 4;
 
// 	A[2].start_time = 3;
// 	A[2].end_time = 5;
 
// 	A[3].start_time = 0;
// 	A[3].end_time = 6;
 
// 	A[4].start_time = 5;
// 	A[4].end_time = 7;
 
// 	A[5].start_time = 3;
// 	A[5].end_time = 9;
 
// 	A[6].start_time = 5;
// 	A[6].end_time = 9;
 
// 	A[7].start_time = 6;
// 	A[7].end_time = 10;
 
// 	A[8].start_time = 8;
// 	A[8].end_time = 11;
 
// 	A[9].start_time = 8;
// 	A[9].end_time = 12;
 
// 	A[10].start_time = 2;
// 	A[10].end_time = 14;
 
// 	A[11].start_time = 12;
// 	A[11].end_time = 16;
 
// 	for (i = 1; i <= N; i++) {
// 		A[i].id = i;
 
// 		//本来是手动输入赋值，这里为了简单，直接将值定死，也可以恢复成手动，将上面从A[1]~A[11]的部分注释掉
// 		//cin >> A[i].start_time >> A[i].end_time;
// 	}
 
// //增加活动结束节点
// 	A[i].id = i;
// 	A[i].start_time = A[i].end_time = 0x7fffffff;
 
// //按结束时间从小到大排序
// 	sort(A, A + N + 2, cmp);
 
// 	Dynamic_Programme();
// cout <<"包含的活动为：";
// 	Print(0, N + 1);
// 	system("pause");
// 	return 0;
// }