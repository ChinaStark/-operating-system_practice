//����һ����ʾ��Ľṹ����Point��һ����ֱ�߷���y = ax + bȷ����ֱ����Line���ṹ����Point��������Աx��y��
//	�ֱ��ʾ��ĺ�����������ꡣLine�����������ݳ�Աa��b���ֱ��ʾֱ�߷����е�ϵ����
//	Line����һ����Ա����print������ʾֱ�߷��̡���Ԫ����setPoint(Line &l1,Line &l2)����������ֱ�ߵĽ��㡣��main�����У�
//��������ֱ�߶��󣬷ֱ����print������ʾ����ֱ�ߵķ��̣������ú���setPoint��������ֱ�ߵĽ��㡣

#include <iostream>
using namespace std;
class Line
{

public:
	void print()
	{
		cout << "ֱ�ߣ�" << "y=" << a << "x+" << b << endl;
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
	cout << "����Ϊ��(" << a.x << "," << a.y<<")";


}