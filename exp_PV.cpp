#include <iostream>
#include<iomanip>
using namespace std;
int v = 0;//循环控件
int le = 0;//数组长度
int b;//时间片
struct Progress
{
	char a[5];
	int NO;//优先级
	int w_time;//还需要工作时间
	int w;
	int hour = 0 ;//已经工作时间
	char statu = 'W';//进程状态
	int a_time;//到达时间
};
void ADD(struct Progress A[] ,int len)
{
	cout << "请输入优先级　需要时间　到达时间　";
	cin >> A[len].NO >> A[len].w_time >> A[len].a_time;
	cout << "给作业取个作业的名字吧：";
	cin >> A[len].a;
	A[len].w = A[len].w_time;

}
void Sort(Progress A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (A[i].NO == A[j].NO)
				if (A[i].a_time > A[j].a_time)
				{
					Progress B = A[i];
					A[i] = A[j];
					A[j] = B;
				}
			if (A[i].NO < A[j].NO)
			{
				Progress B = A[i];
				A[i] = A[j];
				A[j] = B;
			}

		}
	}
	
}
void Caculte(Progress A[], int len)
{
	
	int i = 0;
	A[i].NO--;
	A[i].w_time -= 3;
	A[i].hour += 3;
	if (A[0].w_time <= 0)
	{
		A[0].statu = 'F';
		A[0].hour = A[0].w;
		A[0].NO = -1000;
		A[0].w_time = 0;
	}
}
void Print(Progress A[],int len)
{
	if(A[0].statu != 'F')
		A[0].statu = 'R';//对结束的标志位不改
	for (int i = 0; i < len; i++)
	{
		cout << setw(10) << setiosflags(ios::left)<<A[i].a<< setw(10) << setiosflags(ios::left) << A[i].NO << setw(10) << setiosflags(ios::left) << A[i].a_time << setw(10) << setiosflags(ios::left) << A[i].w_time << setw(10) << setiosflags(ios::left) << A[i].hour << setw(10) << setiosflags(ios::left) << A[i].statu << endl;
	}
	A[0].statu = 'W';
}
void main()
{
	Progress working[6];
	int time = 0;//时间
	int a;
	
	int c = 0;//计数器
	cout << "请输入时间片大小：";
	cin >> b;
	int p = 1;
	while (p)
	{
		cout << " 1、代表的是添加进程\n" << " 2、代表的是打印功能\n" << " 3、代表的是结束退出程序\n" << "请输入序号";
		cin >> a;
		switch (a)
		{
		case 1:
			ADD(working, le);
			le++;
			break;
		case 2:
			while (v != 1)
			{
				Sort(working, le);
				if(working[0].a_time>time)//防止未到就执行
					for (int f = 0; f < le; f++)
					{
						if (working[f].a_time <= time)
						{
							Progress B = working[0];
							working[0] = working[f];
							working[f] = B;
							break;
						}
					}
				if (working[0].statu == 'F')
					v = 1;//结束输出的标志位
				cout << "作业名称 " << "作业优先级 " << "到达时间 " << "所需时间 " << "以做时间 " << "进程状态 " << endl;
				Print(working, le);
				Caculte(working, le);
				time += b;
			}
			break;
		case 3:
			p = 0;
		}
	}
}