#include <iostream>
#include<iomanip>
using namespace std;
struct work
{
	double sub;
    double start;
	double end;
	double working;
	double coe;
	int no;
};
void caculate(struct work worker[], int len)
{
	worker[0].end = worker[0].start + worker[0].working;
	worker[0].coe = 1;
	worker[0].sub = worker[0].start;
	for (int i = 1; i < len; i++)
	{
		worker[i].start = worker[i - 1].end;
		worker[i].end = worker[i].working + worker[i].start;
		worker[i].coe = (worker[i].end - worker[i].sub) / worker[i].working;
	}
}
void show_c(struct work worker[], int len)
{
	cout <<"NO.    "<<"�ύʱ��  " << "��ʼʱ��  " << "����ʱ��  " << "����ʱ��  " << "��ת����  " << "��תϵ��  " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << setw(10) << setiosflags(ios::left)<<worker[i].no<<setw(10)<<setiosflags(ios::left)<< worker[i].sub << setw(10) << setiosflags(ios::left) << worker[i].start << setw(10) << setiosflags(ios::left) << worker[i].working << setw(10) << setiosflags(ios::left) << worker[i].end << setw(10) << setiosflags(ios::left) << worker[i].end - worker[i].sub << setw(10) << setiosflags(ios::left) << worker[i].coe<<endl;
	}
}
void short_c(struct work worker[],int len)
{
	for (int a = 1; a < len; a++)
	{

		for (int v = a + 1; v < len; v++)
		{
			if (worker[a].working > worker[v].working)
			{
				work temp;
				temp = worker[a];
				worker[a] = worker[v];
				worker[v] = temp;
			}
		}

	}
}//����ҵ����
void list_c(struct work worker[], int len)//ʱ������
{
	for (int a = 0; a < len; a++)
	{

		for (int v = a + 1; v < len; v++)
		{
			if (worker[a].start > worker[v].start)
			{
				work temp;
				temp = worker[a];
				worker[a] = worker[v];
				worker[v] = temp;
			}
		}

	}
}
void coe_c(struct work worker[], int len)
{
	int a = worker[0].start + worker[0].working;
	worker[0].end = a;
	for (int i = 1; i < len; i++)
	{
		worker[i].coe = (worker[i].working + a - worker[i].start) / worker[i].working;
	}
	for (int a = 1; a < len; a++)
	{

		for (int v = a + 1; v < len; v++)
		{
			if (worker[a].coe < worker[v].coe)
			{
				work temp;
				temp = worker[a];
				worker[a] = worker[v];
				worker[v] = temp;
			}
		}

	}
}
void com(struct work worker[], int len)
{
	int c;
	cout << "��ѡ����ʲôȨ���� 1������ҵ2��ʱ��3��ϵ��";
	cin >> c;
	switch (c)
	{
	case 1:  short_c(worker, 4); break;
	case 2: list_c(worker, 4); break;
	case 3: list_c(worker, 4); coe_c(worker, 4); break;
	}

}
void main()
{

	work worker[4];
	work worker_b[4];
	double i = 1, j = 1;
	for (int a = 0; a < 4; a++)
	{
		cout << "������" << a << "�ſ�ʼʱ�������ʱ��";
		cin >> i >> j;
		worker[a].no = a+1;
		worker[a].sub = worker[a].start = i;
		worker[a].working = j;
	}
	for (int c = 0; c < 4; c++)
	{
		worker_b[c] = worker[c];
	}
	while (i)
	{
		for (int c = 0; c < 4; c++)
		{
			worker[c] = worker_b[c];
		}
		com(worker, 4);
		caculate(worker , 4);
		show_c(worker, 4);
		cout << "�Ƿ����";
		cin >> i;
	}
	delete[]worker;
	delete worker_b;
}
