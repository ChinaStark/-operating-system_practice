//��д���������뵽��������״��������ά�ĺ���ά�ģ�������һ����״�������ϵ��
//���ɵ�����ϵ��Shape��Ϊ���࣬���ɴ�������TwoDimShape���ThreeDimShape�ࡣ
//���ǵ��������ǲ�ͬ����״�ࡣ��������ϵ�е�ÿ���࣬����main�������в���
#include <iostream>
using namespace std;
class Shape
{
public:
	int len;
	int wid;
	int het;
	
};
class TwoDimShape:public Shape
{
public:
	TwoDimShape(int a,int b)
	{
		len = a;
		wid = b;
	}

};
class ThreeDimShape:public Shape
{
public:
	ThreeDimShape(int a,int b,int c)
	{
		len = a;
		wid = b;
		het = c;
	}
};
class Rectangle:public TwoDimShape
{
public:
	Rectangle(int a, int b):TwoDimShape(a,b)
	{
		area = len * wid;
	}
	void areas()
	{
		cout<<"�þ�������ǣ�"<< area << endl;
	}
private:
	int area;
};
class cube:public ThreeDimShape
{
public:
	cube(int a,int b,int c):ThreeDimShape(a,b,c)
	{
		V = len  * wid  * het;
	}
	void areas()
	{
		cout<<"�������������ǣ�"<< V << endl;
	}
private:
	int V;
};
class Cicle:public TwoDimShape
{
public:
	Cicle(int a, int b):TwoDimShape(a,b)
	{
		aera = 3*a*a;
	}
	void areas()
	{
		cout<<"��Բ����ǣ�"<< aera << endl;
	}
private:
	int aera;
};
void main()
{
	Cicle cicle(1,2);
	cube cube_1(1,2,3);
	Rectangle t1(5,6);
	cicle.areas();
	cube_1.areas();
	t1.areas();
}