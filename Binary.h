#pragma once
#include<iostream>
#include<string.h>
using namespace std;
struct Node
{
public:
	char keyword[10]="";
	int count = 0;
	int num = 0;
};
class SeqList
{
public:
	Node node[32];
	int CreatSeq(char Key[32][10]);
	bool isKeyword(char* word);
	bool isLetter(char ch);
	int ReadFile(char* filename);
	void Show(int key);
	int BiSearch(char* keyword);
	int CalNum();
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
