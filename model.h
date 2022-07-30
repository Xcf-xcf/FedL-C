#ifndef MODEL
#define MODEL
#include<iostream>
#include<vector>
#include"matrix.h"
class LDA//二分类
{
private:
	vector<double> w;       //投影向量即模型参数
public:
	LDA() {};
	void set_para(const vector<double>& para);                   //设置模型参数
	vector<double> get_para();                                   //获取实际类型模型参数
	string para_to_str(const vector<double>& para);              //将实际参数转换为用于通信的文本类型参数
	vector<double> str_to_para(string para);                     //将用于通信的文本类型参数转换为实际参数
	void train(const vector<vector<double> >& data, const vector<int>& labels);//训练模型
	vector<int> predict(const vector<vector<double> >& data);           //输出预测结果
};

#endif
