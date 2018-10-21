#pragma once
#include<iostream>
#include<string.h>
using namespace std;

struct H
{
	char keyword[10] = "";//记录关键词
	int count = 0;//记录关键词出现次数
	int num = 0;//记录比较次数
};
class Hash//Hash表的模板
{
public:
	H hash[42];
	bool isKeyWords(char *word);//判断是否为关键词
	bool isLetter(char ch);
	int CalNum();
	int GetKey(char *keyword);//关键词所在Hash表位置
	int Search(int key);//查找空位
	int CreatHash(char* keyword);//建立Hash表,采用来一个填一个的方式
    int ReadFile(char* filename);
	void Show(int key);
	char KeyWords[32][10] = //构造二维数组存储32个关键字/32代表个数，10代表单词长度
	{
		"auto","break","case","char","const","continue",
		"default","do","double","else","enum","extern",
		"float","for","goto","if","int","long","register",
		"return","short","signed","sizeof","static",
		"struct","switch","typedef","union","unsigned",
		"void","volatile","while",
	};
};

