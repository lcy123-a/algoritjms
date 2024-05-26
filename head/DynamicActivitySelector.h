#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define N 11
 
/*
 * ��Ľṹ�壬��һ��id��һ����ʼʱ�䣬һ������ʱ��
 */
struct activity {
	int id;
	int start_time;
	int end_time;
};
 
//0��ʼ��
int s[N + 2][N + 2] = { 0 };
 
/*
 * ��¼Sij�ܴﵽ��ѵ�һ���ֶλ���±�k��̰���㷨���������Խ���ʱ����������֮��ȡA1������̬�滮׷��ȫ�����ţ�����Ҫ�������п��ܵ�kȡֵ��Ȼ��
 * ȥ����һ���ܴﵽ���ŵĽ⣬�����k���������һ���ڵ�ķֽⷽ��
 */
 
/*��������ȡN+2��ԭ������ΪҪ����һ����ʼ�ͽ���ʱ�䶼��0��0�ڵ��ȥ�����Ա�����11���ڵ㣬�ͱ����11+1���ڵ㣬
 *
 * ����0�ڵ��ԭ������Ϊ��A[i].start_time=0��ʱ������Ҫ��A[i-1].end_time���бȽϣ�����û��ȷ���߽磬�������һ��0�ڵ�
 * Ȼ��������i=N��ʱ�򣬻���Ҫ����A[i].end_time
 * ����Ҫ��A[i+1].start_time�Ƚϣ�����Ҫȡ��i+1=N+1�����������±�ķ�ΧҪ��0~N+2��������ӵĵ�N+1�ڵ�Ϊ��������ԶҲѡ����������
 * �����Ŀ�ʼʱ��ͽ���ʱ�䶼�����0x7fffffff�������java����ܻ�ֱ��ȡInteger.MAX_VALUE
 */
int cut_point[N + 2][N + 2] = { 0 };
 
activity A[N + 2];
 
/*
 * ��̬�滮��������
 */
void Dynamic_Programme() {
 
	int step; //������Ϊj-i���Ĳ�ֵ
	int i, j, k;
	int result;
 
	/*
	 * ��ΪSij��������ڻAi����֮�� �� Aj��ʼ֮ǰ�� ��������ԣ���j<=i+1��ʱ������SijΪ�գ���������step��2��ʼѭ��
	 */
 
	for (step = 2; step <= N + 1; step++) {
 
		//��ÿ�������£������е�i���б���
		for (i = 0; i <= N; i++) {
			j = step + i;
 
			//�������j��N+1���ˣ��Ͳ������ˣ���Ϊ����ֻ��N+1���±�
			if (j <= N + 1) {
 
				//����Sij�Ķ��壬�϶�Ai��Aj�����֮����Ҫ�м��������Sij��Ϊ���ˣ���������i=N��ʱ�򣬻���Ҫ����A[i].end_time
				//����Ҫ��A[i+1].start_time�Ƚϣ�����Ҫȡ��i+1=N+1�����������±�ķ�ΧҪ��0~N+2
				if (A[i].end_time <= A[j].start_time) {
 
					//�ڷ���������k�У�����k��i+1��j֮�䣺[i+1,j)��ȥѰ����ʹ���������ŵ�k��Ҳ����ʹ��Sij��������Ľ�
					for (k = i + 1; k < j; k++) {
 
						//����kҲ��Ҫ���жϣ���Ҫ��Ai��Aj����
						if (A[k].end_time > A[j].start_time
								|| A[k].start_time < A[i].end_time) {
							continue;
						}
 
						//���ݡ��㵼������16.2��ʽ��
						result = s[i][k] + s[k][j] + 1;
						if (result > s[i][j]) {
							s[i][j] = result; //��¼��ǰ�ָʽ�����������
							cut_point[i][j] = k; //���Ҽ�¼��ʱ�ķָ���±�
						}
					}
				}
			}
		}
	}
	cout << "�����ݻ�������Ļ����Ϊ��" << s[0][N + 1] << endl;//����Sij�������ݻ�������Ļ����
}
//��ӡ�������ļ������Sij��
void Print(int start, int end) {
 
	int k = cut_point[start][end];
 
	//��Ϊk=0�������Sij��û�к��ʵĻ����������Ƿָ�㣬������ȥ
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
// //��A[0]Ϊ0ֵ
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
 
// 		//�������ֶ����븳ֵ������Ϊ�˼򵥣�ֱ�ӽ�ֵ������Ҳ���Իָ����ֶ����������A[1]~A[11]�Ĳ���ע�͵�
// 		//cin >> A[i].start_time >> A[i].end_time;
// 	}
 
// //���ӻ�����ڵ�
// 	A[i].id = i;
// 	A[i].start_time = A[i].end_time = 0x7fffffff;
 
// //������ʱ���С��������
// 	sort(A, A + N + 2, cmp);
 
// 	Dynamic_Programme();
// cout <<"�����ĻΪ��";
// 	Print(0, N + 1);
// 	system("pause");
// 	return 0;
// }