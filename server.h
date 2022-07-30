#ifndef SERVER
#define SERVER
#include<iostream>
#include<string>
#include<vector>
#include<exception>
using namespace std;
//���߳�ģ������
class server
{
private:
	string         id;                             //���߳�id
	vector<string> clt_id;                         //�洢�ͻ����̱߳�ʶ
	int            global_epochs;                  //�����ۺϴ��� �������ϴ�/�·�����
	int            local_epochs;                   //�ͻ���ģ��ѵ����������������磩
	vector<int>    batch_size;                     //�ͻ���ÿ��ѵ����ʹ�õ����ݼ���С��ʵ���п���ÿ���ͻ���ÿ��ѵ������С����ͬ,�����ۺ�ʱ��Ҫ�ò������м�Ȩ��
	int            k;                              //ÿ����ѡk���ͻ����߳̽���ѵ�����ϴ��������ȼ򻯿ͻ���ѡ����̣�������ʱ��������ʵ��һ�㣩
	void*          model;                          //ʵ������ģ����ָ�룺���ڱ�����һ�־ۺϺ�Ĳ����Լ�ģ������
public:
	server(string Id, vector<string> Clt_id, int Global_epochs, int Local_epochs, vector<int> Batch_size, int K, void* Model)
	{
		id = Id;
		clt_id.assign(Clt_id.begin(), Clt_id.end());
		global_epochs = Global_epochs;
		local_epochs = Local_epochs;
		batch_size.assign(Batch_size.begin(), Batch_size.end());
		k = K;
		model = Model;
	}
	bool  select_clt(vector<string>& clt);                                 //ʹ�������ѡ��ͻ��˽���ѵ����clt�洢��ѡ�ͻ���id��
	bool  send_para(string clt);                                           //ͨ��ģ��ָ�����ģ���еĻ�ȡ�����ĺ���������idΪclt�Ŀͻ��˷��;ۺϺ�Ĳ���
	void* get_para(string clt);                                            //��idΪclt�Ŀͻ��˽���ѵ���õ�ģ�Ͳ����������غ��иò�����ģ��ָ��
	bool  para_fusion(vector<string>& clt);                                //��������ѡ��Ŀͻ��˲�������ʹ��fed_avg�����ۺϲ���
	void  evaluate(vector<vector<double> > test_data, vector<int> labels);  //����ѵ����������ǰģ�ͣ��Է�������Ϊ��������roc��pr���ߵȣ���û������󣬾�ȷ�ʣ���ȫ�ʣ���׼�ʵȣ�
};
#endif