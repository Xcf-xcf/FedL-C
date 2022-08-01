#include"matrix.h"
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

vector<vector<double> > eye(int n, int m)
{
	vector<vector<double> > x(n,vector<double>(m));
	int mi = min(n, m);
	for (int i = 0; i < mi; i++)
	{
		x[i][i] = 1;
	}
	return x;
}

vector<vector<double> > diag(vector<double> a)
{
	int siz = a.size();
	vector<vector<double> > x(siz, vector<double>(siz));
	for (int i = 0; i < siz; i++)
	{
		x[i][i] = a[i];
	}
	return x;
}

double det(vector<vector<double> > a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j][i] != 0)
				{
					swap(a[i], a[j]);
					break;
				}
			}
			if (a[i][i] == 0)
				return 0;
		}
		for (int k = i + 1; k < n; k++)
		{
			double t = a[k][i] / a[i][i];
			for (int j = i; j < n; j++)
			{
				a[k][j] -= t * a[i][j];
			}
		}
	}
	double x = 1;
	for (int i = 0; i < n; i++)
	{
		x *= a[i][i];
	}
	return x;
}

vector<vector<double> > mul(const vector<vector<double> >& a, const vector<vector<double> >& b)
{
	int n = a.size(), m = b[0].size(), d=a[0].size();
	vector<vector<double> > x(n, vector<double>(m,0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < d; k++)
			{
				x[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return x;
}

vector<vector<double> > mul(const vector<vector<double> >& a, double b)
{
	vector<vector<double> > x = a;
	int n = x.size(), m = x[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] *= b;
		}
	}
	return x;
}

vector<vector<double> > mul(double b, const vector<vector<double> >& a)
{
	vector<vector<double> > x = a;
	int n = x.size(), m = x[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] *= b;
		}
	}
	return x;
}

vector<vector<double> > add(const vector<vector<double> >& a, const vector<vector<double> >& b)
{
	int n = a.size(), m = a[0].size();
	vector<vector<double> > x(n, vector<double>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] = a[i][j] + b[i][j];
		}
	}
	return x;
}

vector<vector<double> > inv(const vector<vector<double> >& a)
{
	int n = a.size();
	vector<vector<double> > D(n, vector<double>(2 * n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			if (j < n)
			{
				D[i][j] = a[i][j];
			}
			else
			{
				if ((j - n) == i)
				{
					D[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (D[i][i] == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (D[j][i] != 0)
				{
					swap(D[i], D[j]);
				}
			}
			if (D[i][i] == 0)
			{
				throw - 1;
			}
		}
		double t = D[i][i];
		for (int j = i; j < 2*n; j++)
		{
			D[i][j] /= t;
		}
		for (int k = 0; k < n; k++)
		{
			if (k == i)continue;
			t = -D[k][i];
			for (int j = i; j < 2 * n; j++)
			{
				D[k][j] += t * D[i][j];
			}
		}
	}
	vector<vector<double> > x(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = D[i][j + n];
		}
	}
	return x;
}