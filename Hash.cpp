#pragma once
#include"Hash.h"
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//判断
bool Hash::isKeyWords(char *word)
{
	for (int i = 0; i < 32; i++)
	{
		if (strcmp(word, KeyWords[i]) == 0)//如果是关键词
			return true;
	}
	return false;//如果都找不到就不是关键词
}
//查找关键词位置
int Hash::GetKey(char* keyword)
{
	return (keyword[0] * 100 + keyword[strlen(keyword) - 1]) %41;
}
//找空位
int Hash::Search(int key)
{
	if (key<0 || key >= 41) return -1;
	for (int i = key + 1; i < 41; i++)
	{
		if (strlen(hash[i].keyword) == 0)//如果为空
		{
			hash[i].num = hash[key].num + (i - key);
			return i;
		}
	}
	for (int j = 0; j < key; j++)
	{
		if (strlen(hash[j].keyword) == 0)//如果为空
		{
			hash[j].num = hash[key].num + j + (42 - key);
			return j;
		}
	}
	return -1;
}
//构造Hash表
int Hash::CreatHash(char* keyword)
{
	
	//先判断
	if (!isKeyWords(keyword))
		return -1;
	//判断Hash位置
	int key = GetKey(keyword);
	//如果为当前位置为空,则插入
	if (strlen(hash[key].keyword) == 0)
	{
		strcpy(hash[key].keyword, keyword);
		hash[key].count++;
		hash[key].num++;
		return 1;
	}
	else
	{
		//如果不为空，且相同
		if (strcmp(hash[key].keyword, keyword) == 0)
		{
			hash[key].count++;
			return 1;
		}
		//如果不为空，且不相同
		else
		{
			int emptyseat=Search(key);//寻找空的位置
			strcpy(hash[key].keyword, keyword);//在空的位置插入关键词
			hash[emptyseat].count++;
			return 1;
		}
	}
	cout << "over";
}
bool Hash::isLetter(char ch)
{
	if ((ch >= 'a'&&ch <= 'z')|| (ch >= 'A'&&ch <= 'Z'))
		return true;
	return false;
}
int Hash::CalNum()
{
	int sum=0;
	for (int j = 0; j < 41; j++)
	{
		sum = sum + (hash[j].count*hash[j].num);
	}
	return sum;
}
int Hash::ReadFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	char text[1024];
	while (!feof(file))//直到文件的结尾
	{
		int i = 0;
		char word[10] = { "" };
		char ch = fgetc(file);//读入一个字符
		while (!isLetter(ch)&& feof(file) == 0)//往下读直到是字母 
			ch = fgetc(file);
		while (isLetter(ch) && feof(file) == 0)//如果遇到了字母，就要开始放到Hash表中了
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
					   //进行判断
		if (isKeyWords(word))
			CreatHash(word);
	}
	fclose(file);
	return 1;
}
//=========================================界面相关
void Hash::Show(int key)
{
	if (strlen(hash[key].keyword) == 0)
	{
		cout << "哈希表的位置:" << key << "     出现次数为0" << '\n';
		return;
	}
	cout << "哈希表的位置:" << key << "     关键字:" << hash[key].keyword << "     出现次数:" << hash[key].count << "\n";
}
