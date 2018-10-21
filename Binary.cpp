#pragma once
#include"Binary.h"
#include<cstring>
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int SeqList::CreatSeq(char Key[32][10])
{
//对字符数组按照string型排序
/*	char temp[10]="";
	for (int i = 0; i < 32; i++)//执行排序。选择法。
		for (int j = i + 1; j<32; j++)
		{
			if (strcmp(Key[i],Key[j]) > 0)//比较
			{
				strcpy(temp, Key[i]);
				strcpy(Key[i],Key[j]);
				strcpy(Key[j],temp);//这三句为交换。
			}
		}*/
	//==========================添加进顺序表
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Key[i][j]>='a'&&Key[i][j]<='z')
			{
				node[i].keyword[j]=Key[i][j];
			}
		}
	}
	return 1;
}
bool SeqList::isKeyword(char* word)
{
	for (int i = 0; i < 32; i++)
	{
		if (strcmp(word, KeyWords[i]) == 0)//如果是关键词
			return true;
	}
	return false;//如果都找不到就不是关键词
}
bool SeqList::isLetter(char ch)
{
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		return true;
	return false;
}
int SeqList::BiSearch(char* keyword)
{
	int low = 0;//从0开始
	int high = 31;//到31为止一共32个Keyword
	int mid;
	int s = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(KeyWords[mid],keyword)==0)
		{
			node[mid].count++;
			s++;
			node[mid].num = s;
			return 1;
		}
		else if (strcmp(KeyWords[mid], keyword)<0)
		{
			low = mid + 1;
			s++;
		}
		else
		{
			high = mid - 1;
			s++;
		}
	}
	return -1;
}
int SeqList::CalNum()
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
		sum = sum + node[i].count*node[i].num;
	return sum;
}
int SeqList::ReadFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	char text[1024];
	while (!feof(file))//直到文件的结尾
	{
		int i = 0;
		char word[10] = { "" };
		char ch = fgetc(file);//读入一个字符
		while (!isLetter(ch) && feof(file) == 0)//往下读直到是字母 
			ch = fgetc(file);
		while (isLetter(ch) && feof(file) == 0)//如果遇到了字母
		{
			//如果超过10个字母说明肯定不是,于是跳到下一个单词
			if (i == 10)
			{
				while (isLetter(ch) && feof(file) == 0)
				{
					ch = getc(file);
				}
				i = 0;
				break;
			}
			else//存在数组word中组成单词进行判断和添加
			{
				word[i] = ch;
				i++;
				ch = getc(file);
			}
		}
		word[i] = '\0';//数组以\0结束
		if(isKeyword(word))
		   BiSearch(word);
	}
	fclose(file);
	return 1;
}
void SeqList::Show(int key)
{
	cout << "关键词"<<node[key].keyword << "    出现的次数为：" << node[key].count<<"\n";
}