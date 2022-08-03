#ifndef MODEL
#define MODEL
#include<iostream>
#include<vector>
#include"matrix.h"

double accuracy(vector<int> true_labels, vector<int> pred_labels);//��ȷ��

vector<double> precision(vector<int> true_labels, vector<int> pred_labels);//��׼��

vector<double> recall(vector<int> true_labels, vector<int> pred_labels);//��ȫ��

double ROC(vector<int> true_labels, vector<int> pred_labels);//ROC����

class LDA//������
{
private:
	vector<double> w;       //ͶӰ������ģ�Ͳ���
	double threshold;       //������ֵ
public:
	LDA() {};
	void set_para(const vector<double>& para);                   //����ģ�Ͳ���
	vector<double> get_para();                                   //��ȡʵ������ģ�Ͳ���
	string para_to_str(const vector<double>& para);              //��ʵ�ʲ���ת��Ϊ����ͨ�ŵ��ı����Ͳ���
	vector<double> str_to_para(string para);                     //������ͨ�ŵ��ı����Ͳ���ת��Ϊʵ�ʲ���
	void train(const vector<vector<double> >& data, const vector<int>& labels);//ѵ��ģ��
	vector<int> predict(const vector<vector<double> >& data);           //���Ԥ����
};

#endif
