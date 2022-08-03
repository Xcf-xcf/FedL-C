#ifndef CLIENT
#define CLIENT
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//�����̲߳�ʹ���ź�������ģ��ͻ���������֮���ͨ��
class client
{
private:
	string id;                           //�߳�id
	string server_id;                    //���߳�id
	void* model;                         //ģ��ָ��
	int local_epochs;                    //ѵ�������������������ԣ�
	int batch_size;                      //ÿ��ѵ�������ѡȡ����������С
	vector<vector<double> > data;        //��ʾ������ѧϰ�����иÿͻ�����ӵ�е���������
public:
	client(string Id, void* Model, int Local_epochs, int Batch_size, vector<vector<double> >& Data)
	{
		id = Id;
		model = Model;
		local_epochs = Local_epochs;
		batch_size = Batch_size;
		data.assign(Data.begin(), Data.end());
		//�����̻߳����

	}
	bool  send_para();                   //ͨ��ģ��ָ�����ģ���еĻ�ȡ�����ĺ������������˷���ѵ���õĲ���
	void* get_para();                    //���շ���˾ۺϺ�Ĳ����������غ��иò�����ģ��ָ�루��������ģ�ͻ����Դ˲�����ʼ����һ��������ģ�ͣ�
	bool  run();                         //�߳������еĺ���������ģ��ѵ�����ϴ������Ȳ��裩
};
#endif
