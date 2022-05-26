// ����������X = ( x1, x2,��, xn)��Y = ( y1, y2,��, yn )������֮��ļӡ����ͳ˷��ֱ���Ϊ��
//X + Y = ( x1 + y1, x2 + y2,��, xn + yn )
//X - Y = ( x1 - y1, x2 - y2,��, xn - yn )
//X * Y = x1 * y1 + x2 * y2 +��+ xn * yn
//��д������������Vector�����������+��-��*��=��ʵ������֮��ļӡ�
//�����ˡ���ֵ���㣻���������>>��<<ʵ�����������롢������ܡ�ע��������ĺϷ��ԡ�
//��ʾ������������������ǣ�
#include <iostream>
using namespace std;
class Vector
{
private:
	double* v;
	int len;
public:
	Vector(int size);
	Vector(double*, int);
	~Vector()
	{
		//delete[]v;
	}
	double& operator[](int i);
	Vector& operator =(Vector&);
	friend Vector operator +(Vector&, Vector&);
	friend Vector operator - (Vector&, Vector&);
	friend double operator *(Vector&, Vector&);
	friend ostream& operator <<(ostream& output, Vector&);
	friend istream& operator >>(istream& input, Vector&);
};
double operator *(Vector& p, Vector& q)
{
	int e = q.len;
	double mq = 0;
	for (int i = 0; i < q.len; i++)
		mq += (p[i] * q[i]);
	return mq;
}
Vector operator - (Vector& p, Vector& q)
{
	int e = q.len;
	Vector A(e);
	for (int i = 0; i < q.len; i++)
		A[i] = p[i] - q[i];
	return A;
}
Vector operator +(Vector& p, Vector& q)
{
	int e = q.len;
	Vector A(e);
	for (int i = 0; i < q.len; i++)
		A[i] = p[i] + q[i];
	return A;
}
Vector& Vector::operator =(Vector& p)
{
	len = p.len;
	v = new double[len + 1];
	for (int i = 0; i < len; i++)
		v[i] = p[i];
	return *this;

}
double& Vector::operator[](int i)
{
	return v[i];
}
istream& operator >>(istream& input, Vector& p)
{
	for (int i = 0; i < p.len; i++)
	{
		input >> p[i];
	}
	return input;
}
ostream& operator <<(ostream& output, Vector& p)
{
	for (int i = 0; i < p.len; i++)
	{
		output << "      "<< p[i];
	}
	return output;
}
Vector::Vector(int size)
{
	len = size;
	v = new double[size + 1];
	for (int i = 0; i < len; i++)
		v[i] = 0;
}
Vector::Vector(double* p, int t)
{
	len = t;
	v = new double[len + 1];
	for (int i = 0; i < len; i++)
		v[i] = p[i];
}




void main()
{
	Vector A(5);
	Vector B(5);
	cout << "������A������";
	cin >> A;
	//cout << A;
	cout << "������A������";
	cin >> B;
	double q = A * B;
	Vector C = A - B;
	Vector D = A + B;
	cout << "A*B�Ľ���ǣ�" << q << endl;
	cout << "A-B�Ľ���ǣ�" << C << endl;
	cout << "A-B�Ľ���ǣ�" << D << endl;
}