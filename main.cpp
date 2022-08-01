#include"matrix.h"
#include<iostream>
using namespace std;
int main()
{
	vector<vector<double> > x=eye(2,2);
	vector<double> x1(2, 1);
	vector<double> x2(2, 2);
	vector<vector<double> > xx = x;
	x[0][0] = 0;
	x[0][1] = 0;
	x[1][0] = 0;
	x[1][1] = 4;
	vector<vector<double> > y = add(x, xx);
	try { y = inv(x); }
	catch (int e)
	{
		printf("A\n");
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%lf ", x[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%lf ", y[i][j]);
		}
		printf("\n");
	}
	printf("%lf", det(x));
}