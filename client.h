#ifndef CLIENT
#define CLIENT
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//创建线程并使用信号量机制模拟客户端与服务端之间的通信
class client
{
private:
	string id;                           //线程id
	string server_id;                    //主线程id
	void* model;                         //模型指针
	int local_epochs;                    //训练轮数（针对神经网络而言）
	int batch_size;                      //每轮训练中随机选取的数据量大小
	vector<vector<double> > data;        //表示在联邦学习过程中该客户端所拥有的所有数据
public:
	client(string Id, void* Model, int Local_epochs, int Batch_size, vector<vector<double> >& Data)
	{
		id = Id;
		model = Model;
		local_epochs = Local_epochs;
		batch_size = Batch_size;
		data.assign(Data.begin(), Data.end());
		//创建线程或进程

	}
	bool  send_para();                   //通过模型指针调用模型中的获取参数的函数，并向服务端发送训练好的参数
	void* get_para();                    //接收服务端聚合后的参数，并返回含有该参数的模型指针（用以评估模型或者以此参数初始化下一轮神经网络模型）
	bool  run();                         //线程中运行的函数（进行模型训练，上传参数等步骤）
};
#endif
