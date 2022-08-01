#ifndef MATRIX
#define MATRIX
#include<iostream>
#include<vector>
using namespace std;

vector<vector<double> > eye(int n, int m);

vector<vector<double> > diag(vector<double> a);

double det(vector<vector<double> > a);                                             //行列式

vector<vector<double> > mul(const vector<vector<double> >& a, const vector<vector<double> >& b);//两矩阵相乘

vector<vector<double> > mul(const vector<vector<double> >& a, double b);

vector<vector<double> > mul(double b, const vector<vector<double> >& a);

vector<vector<double> > inv(const vector<vector<double> >& a);                            //矩阵求逆

vector<vector<double> > add(const vector<vector<double> >& a, const vector<vector<double> >& b);//矩阵加法

#endif
