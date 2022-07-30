#ifndef MODEL
#define MODEL
#include<iostream>
#include<vector>
#include"matrix.h"
class LDA//������
{
private:
	vector<double> w;       //ͶӰ������ģ�Ͳ���
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
