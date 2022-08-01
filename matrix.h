#ifndef MATRIX
#define MATRIX
#include<iostream>
#include<vector>
using namespace std;

vector<vector<double> > eye(int n, int m);

vector<vector<double> > diag(vector<double> a);

double det(vector<vector<double> > a);                                             //����ʽ

vector<vector<double> > mul(const vector<vector<double> >& a, const vector<vector<double> >& b);//���������

vector<vector<double> > mul(const vector<vector<double> >& a, double b);

vector<vector<double> > mul(double b, const vector<vector<double> >& a);

vector<vector<double> > inv(const vector<vector<double> >& a);                            //��������

vector<vector<double> > add(const vector<vector<double> >& a, const vector<vector<double> >& b);//����ӷ�

#endif
