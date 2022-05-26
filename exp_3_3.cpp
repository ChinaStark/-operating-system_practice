// 假设有向量X = ( x1, x2,…, xn)和Y = ( y1, y2,…, yn )，它们之间的加、减和乘法分别定义为：
//X + Y = ( x1 + y1, x2 + y2,…, xn + yn )
//X - Y = ( x1 - y1, x2 - y2,…, xn - yn )
//X * Y = x1 * y1 + x2 * y2 +…+ xn * yn
//编写程序定义向量类Vector，重载运算符+、-、*和=，实现向量之间的加、
//减、乘、赋值运算；重载运算符>>、<<实现向量的输入、输出功能。注意检测运算的合法性。
//提示：向量类的声明可以是：
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
	cout << "请输入A向量：";
	cin >> A;
	//cout << A;
	cout << "请输入A向量：";
	cin >> B;
	double q = A * B;
	Vector C = A - B;
	Vector D = A + B;
	cout << "A*B的结果是：" << q << endl;
	cout << "A-B的结果是：" << C << endl;
	cout << "A-B的结果是：" << D << endl;
}