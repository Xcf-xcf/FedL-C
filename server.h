#ifndef SERVER
#define SERVER
#include<iostream>
#include<string>
#include<vector>
#include<exception>
using namespace std;
//主线程模拟服务端
class server
{
private:
	string         id;                             //主线程id
	vector<string> clt_id;                         //存储客户端线程标识
	int            global_epochs;                  //参数聚合次数 即参数上传/下发次数
	int            local_epochs;                   //客户端模型训练次数（针对神经网络）
	vector<int>    batch_size;                     //客户端每次训练所使用的数据集大小（实际中可能每个客户端每次训练集大小不相同,参数聚合时需要该参数进行加权）
	int            k;                              //每轮挑选k个客户端线程进行训练并上传参数（先简化客户端选择过程，后期有时间再做得实际一点）
	void*          model;                          //实例化的模型类指针：用于保存上一轮聚合后的参数以及模型评估
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
	bool  select_clt(vector<string>& clt);                                 //使用随机数选择客户端进行训练，clt存储所选客户端id。
	bool  send_para(string clt);                                           //通过模型指针调用模型中的获取参数的函数，并向id为clt的客户端发送聚合后的参数
	void* get_para(string clt);                                            //从id为clt的客户端接受训练好的模型参数，并返回含有该参数的模型指针
	bool  para_fusion(vector<string>& clt);                                //接受所有选择的客户端参数，并使用fed_avg方法聚合参数
	void  evaluate(vector<vector<double> > test_data, vector<int> labels);  //根据训练集评估当前模型（以分类问题为例，绘制roc，pr曲线等，求得混淆矩阵，精确率，查全率，查准率等）
};
#endif