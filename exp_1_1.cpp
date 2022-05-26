//试写出你所能想到的所有形状（包括二维的和三维的），生成一个形状层次类体系。
//生成的类体系以Shape作为基类，并由此派生出TwoDimShape类和ThreeDimShape类。
//它们的派生类是不同的形状类。定义类体系中的每个类，并用main函数进行测试
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
		cout<<"该矩形面积是："<< area << endl;
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
		cout<<"该立方体的体积是："<< V << endl;
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
		cout<<"该圆面积是："<< aera << endl;
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