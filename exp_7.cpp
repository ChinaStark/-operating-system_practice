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
	while (!read_data.eof())	//û���ļ���β
	{
		char a[1024];
		read_data >> a;
		cout << a;
	}
	read_data.close();
}
void delete_file(string a)
{
	if (_access(a.c_str(), 0) == 0)//0�������accessֻ��������ļ����Ƿ����
		remove(a.c_str());
	else
		cout << "�ļ�������";
}
void write_data(string a)
{
	ofstream write_data;
	write_data.open(a.c_str(), ios::out);
	char aa[1024];
	cout << "�������ļ�����:";
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
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_READONLY); break;//��Ϊֻ��
	case 2:
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_HIDDEN); break;//��Ϊ����
	case 3:
		SetFileAttributes(lpFileName, FILE_ATTRIBUTE_NORMAL); break;//��Ϊ������ȡ�����������趨
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