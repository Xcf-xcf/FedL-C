#include"matrix.h"
#include"model.h"
#include"data.h"
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<set>
using namespace std;
int main()
{
	vector<vector<double> > data;
	vector<int> labels;
	vector< vector<vector<double> > > data_sect;
	vector<vector<int> > labels_sect;
	read_in(data, labels, "data.txt", "labels.txt");
	vector<double> x({ 0.7,0.3 });
	//cout << x[0] << ' ' << x[1];
	split_data(data_sect, labels_sect, data, labels, x);
	class LDA lda;
	lda.train(data_sect[0], labels_sect[0]);
	//vector<double> w = lda.get_para();
	//cout << w.size() << endl << data[0].size();
	vector<int> pred_labels = lda.predict(data_sect[1]);
	cout << "准确率:" << accuracy(labels_sect[1], pred_labels) << endl;
	cout << "查准率:" <<  precision(labels_sect[1], pred_labels)[0] << ' ' << precision(labels_sect[1], pred_labels)[1] << endl;
	cout << "查全率:" <<  recall(labels_sect[1], pred_labels)[0] << ' ' << recall(labels_sect[1], pred_labels)[1] << endl;
	
	/*
	vector<vector<double> > x=eye(2,2);
	vector<double> x1(4);
	vector<double> x2(2, 2);
	vector<vector<double> > xx(2,vector<double>(x2.begin(),x2.end()));
	x[0][0] = 2;
	x[0][1] = 1;
	x[1][0] = 3;
	x[1][1] = 4;
	x1[0] = 2;
	x1[1] = 1;
	x1[2] = 2;
	x1[3] = 3;
	string s = "0.1 0.2 0.3";
	stringstream ss(s);
	double buf;
	int a = 0.3 * 9;
	cout << a<<endl;
	while (ss >> buf)
	{
		cout << buf << endl;
	}
	set<double> s(x1.begin(), x1.end());
	for (set<double>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it) << endl;
	}
	vector<vector<double> > y = add(x, xx);
	x = cov(x);
	double a = 0.123456789123456;
	//cout << x1[0] << ' ' << x1[1] << endl;
	vector<double> x3;
	x3.assign(x1.begin(), x1.end() - 1);
	cout << x3.size() << ' ' << x3[0];
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
	*/
}