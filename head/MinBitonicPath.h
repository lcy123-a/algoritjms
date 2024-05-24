//双调欧几里得旅行商问题
//《算法导论（第二版）》思考题15-1
//PKU 2677
 
#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
const int n = 7;//点的数目
const int MaxVal = 999999;
const int MaxLen = 201;
 
struct tagPoint{
	double x,y;
};
 
//计算点i和点j之间的直线距离
double distance(tagPoint *points,int i,int j)
{
	return sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) +
		(points[i].y - points[j].y) * (points[i].y - points[j].y));
}
 
double DP(tagPoint *points,int n)
{
	double b[MaxLen][MaxLen];//记录最短路径的长度
	//计算所有情况下的b[i][j]，1 <= i <= j
	//初始化
	b[1][2] = distance(points,1,2);
	for (int j = 3;j <= n;++j)
	{
		//i < j-1
		for (int i = 1;i <= j - 2;++i)
		{
			b[i][j] = b[i][j - 1] + distance(points,j - 1,j);
		}
		//i = j - 1,b[i][j] = min(b[k][j - 1] + distance(k,j));
		b[j - 1][j] = MaxVal;
		for (int k = 1;k <= j - 2;++k)
		{
			double temp = b[k][j - 1] + distance(points,k,j);
			if (temp < b[j - 1][j])
			{
				b[j - 1][j] = temp;
			}
		}
	}
 
	b[n][n] = b[n - 1][n] + distance(points,n - 1,n);
 
	return b[n][n];
}
 
