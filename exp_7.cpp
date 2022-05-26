#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdio.h>
#include<direct.h>
#include<io.h>
using namespace std;
void readfile(string a)
{
	ifstream read_data;
	read_data.open(a.c_str(), ios::in);
	while (!read_data.eof())	//没到文件结尾
	{
		char a[1024];
		read_data >> a;
		cout << a;
	}
	read_data.close();
}
void delete_file(string a)
{
	if (_access(a.c_str(), 0) == 0)//0代表的是access只用来检测文件夹是否存在
		remove(a.c_str());
	else
		cout << "文件不存在";
}
void write_data(string a)
{
	ofstream write_data;
	write_data.open(a.c_str(), ios::out);
	char aa[1024];
	cout << "请输入文件内容:";
	cin >> a;
	write_data << a;
	write_data.close();
}
void set_formate(const char* a, int f)
{
	WCHAR w[64];
	swprintf(w, L"%S", a);
	LPCWSTR lpFileName = w;
	switch (f)
	{
	case 1:
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_READONLY); break;//设为只读
	case 2:
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_HIDDEN); break;//设为隐藏
	case 3:
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_NORMAL); break;//设为正常，取消所有属性设定
	}
}
void main()
{
	string a = "./wenjian.txt";
	write_data(a);
	readfile(a);
	set_formate(a.c_str(), 3);
	//delete_file(a);
}