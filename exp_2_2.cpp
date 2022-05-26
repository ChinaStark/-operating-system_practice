//定义一个表示点的结构类型Point和一个由直线方程y = ax + b确定的直线类Line。结构类型Point有两个成员x和y，
//	分别表示点的横坐标和纵坐标。Line类有两个数据成员a和b，分别表示直线方程中的系数。
//	Line类有一个成员函数print用于显示直线方程。友元函数setPoint(Line &l1,Line &l2)用于求两条直线的交点。在main函数中，
//建立两个直线对象，分别调用print函数显示两条直线的方程，并调用函数setPoint求这两条直线的交点。

#include <iostream>
using namespace std;
class Line
{

public:
	void print()
	{
		cout << "直线：" << "y=" << a << "x+" << b << endl;
	}
	Line(int a1, int b1)
	{
		a = a1;
		b = b1;
	}
	int a;
	int b;


};
class Point
{
public:

	friend  Point setPoint(Line& l1, Line& l2);

	int x;
	int y;

};

Point setPoint(Line& l1, Line& l2)
{
	int q= (l1.b - l2.b) / (l2.a - l1.a);
	int w = (l1.a) * q + l1.b;
	Point aa;
	aa.x = q;
	aa.y = w;
	return aa;
}
void main()
{
	Line l1(2, 3);
	Line l2(3, 6);
	Point a;
	l1.print();
	l2.print();
	a = setPoint(l1, l2);
	cout << "交点为：(" << a.x << "," << a.y<<")";


}