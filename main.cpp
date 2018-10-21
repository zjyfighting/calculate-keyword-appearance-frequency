#include"Hash.h"
#include"Binary.h"
#include<iostream>
using namespace std;
char KeyWords[32][10] = //构造二维数组存储32个关键字/32代表个数，10代表单词长度
{
	"auto","break","case","char","const","continue",
	"default","do","double","else","enum","extern",
	"float","for","goto","if","int","long","register",
	"return","short","signed","sizeof","static",
	"struct","switch","typedef","union","unsigned",
	"void","volatile","while",
};
void menu()
{
	cout << "\t===========请选择功能\n";
	cout << "\t===========1.利用Hash技术\n";
	cout << "\t===========2.利用顺序表技术\n";
	cout << "\t===========3.退出\n";
}

int main()
{
	while(1)
	{
	Hash hx;
	SeqList seq;
	int sr;
	menu();
	cin >> sr;
	switch (sr)
	{
	case 1:
	{
		hx.ReadFile("Binary.cpp");
		for (int i = 0; i < 41; i++)
		{
			hx.Show(i);
		}
		int s = hx.CalNum();
		cout << "关键词查找总次数为：" << s << "\n\n\n";
		break;
	}


	case 2:
	{
		seq.CreatSeq(KeyWords);
		seq.ReadFile("Binary.cpp");
		for(int i=0;i<32;i++)
		{
			seq.Show(i);
		}
		int s = seq.CalNum();
		cout << "关键词查找总次数为：" << s << "\n\n\n";
		break;
	}
	case 3:
	{
		return 0;
	}
	default: 
	{
		cout << "请输入正确的值\n";
		break;
	}
	}
	}
}