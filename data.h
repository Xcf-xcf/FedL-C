#ifndef DATA
#define DATA
#include"data.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void read_in(vector<vector<double> >& data, vector<int>& labels, string dataPath, string labelsPath);

void split_data(vector< vector<vector<double> > >& data_sect, vector<vector<int> >& labels_sect, const vector<vector<double> >& data, const vector<int>& labels, const vector<double>& ratio);

#endif
