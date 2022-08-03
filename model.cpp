#include"matrix.h"
#include"model.h"
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<set>
#include <cassert>
using namespace std;

double accuracy(vector<int> true_labels, vector<int> pred_labels)
{
	double acc=0;
	set<int> cls(true_labels.begin(), true_labels.end());
	for (set<int>::iterator it = cls.begin(); it != cls.end(); it++)
	{
		acc += sum((true_labels == (*it))&&(pred_labels == (*it)));
	}
	acc /= (1.0 * true_labels.size());
	return acc;
}

vector<double> precision(vector<int> true_labels, vector<int> pred_labels)
{
	set<int> cls(true_labels.begin(), true_labels.end());
	vector<double> x;
	for (set<int>::iterator it = cls.begin(); it != cls.end(); it++)
	{
		x.push_back(1.0 * sum((true_labels == (*it)) && (pred_labels == (*it))) / sum(pred_labels == (*it)));
	}
	return x;
}

vector<double> recall(vector<int> true_labels, vector<int> pred_labels)
{
	set<int> cls(true_labels.begin(), true_labels.end());
	vector<double> x;
	for (set<int>::iterator it = cls.begin(); it != cls.end(); it++)
	{
		x.push_back(1.0 * sum((true_labels == (*it)) && (pred_labels == (*it))) / sum(true_labels == (*it)));
	}
	return x;
}

void LDA::set_para(const vector<double>& para)
{
	threshold = para[para.size() - 1];
	w.assign(para.begin(), para.end()-1);
}

vector<double> LDA::get_para()
{
	vector<double> para(w.begin(), w.end());
	para.push_back(threshold);
	return para;
}

string LDA::para_to_str(const vector<double>& para)
{
	int n = para.size();
	string str = "";
	for (int i = 0; i < n; i++)
	{
		if (i)
			str = str + " ";
		stringstream ss;
		ss << setprecision(15) << para[i];
		str = str + ss.str();
	}
	return str;
}

vector<double> LDA::str_to_para(string para)
{
	stringstream ss(para);
	string buf;
	vector<double> p;
	while (ss >> buf)
	{
		p.push_back(stod(buf));
	}
	return p;
}

void LDA::train(const vector<vector<double> >& data, const vector<int>& labels)
{
	vector<vector<double> > d0=row(data, labels == 0), d1= row(data, labels == 1);
	vector<vector<double> > s0 = cov(d0), s1 = cov(d1);
	vector<double> m0 = mean(d0), m1 = mean(d1);
	vector<vector<double> > M0 = T(vector<vector<double> >(1, vector<double>(m0.begin(), m0.end())));
	vector<vector<double> > M1 = T(vector<vector<double> >(1, vector<double>(m1.begin(), m1.end())));
	vector<vector<double> > s = add(s0, s1);
	s = add(s, mul(1e-6, eye(s.size(), s.size())));
	//cout << M0.size() << endl;
	vector<vector<double> > t = T(mul(s,add(M0,mul(-1,M1))));
	w = t[0];
	M0 = T(M0);
	M1 = T(M1);
	threshold = mul(add(mul(0.5, M0), mul(0.5, M1)), T(vector<vector<double> >(1, vector<double>(w.begin(), w.end()))))[0][0];
}

vector<int> LDA::predict(const vector<vector<double> >& data)
{
	int n = data.size();
	vector<int> labels(n);
	vector<vector<double> > y = mul(data, T(vector<vector<double> >(1, vector<double>(w.begin(), w.end()))));
	for (int i = 0; i < n; i++)
	{
		if (y[i][0] >= threshold)
		{
			labels[i] = 0;
		}
		else
		{
			labels[i] = 1;
		}
	}
	return labels;
}