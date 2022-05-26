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
void average(struct work worker[], int len)
{
	worker[len].coe = 0;
	worker[len].start = 0;
	for (int i = 0; i < len; i++)
	{
		worker[len].coe += worker[i].coe;
		worker[len].start += (worker[i].end - worker[i].sub);
	}
	cout << "平均周转周期:" << (worker[len].start) / len << "t" << "平均周转系数:" << (worker[len].coe) / len << endl;
}
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
	cout << "NO.    " << "提交时刻  " << "开始时刻  " << "运行时间  " << "结束时刻  " << "周转周期  " << "周转系数  " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << setw(10) << setiosflags(ios::left) << worker[i].no << setw(10) << setiosflags(ios::left) << worker[i].sub << setw(10) << setiosflags(ios::left) << worker[i].start << setw(10) << setiosflags(ios::left) << worker[i].working << setw(10) << setiosflags(ios::left) << worker[i].end << setw(10) << setiosflags(ios::left) << worker[i].end - worker[i].sub << setw(10) << setiosflags(ios::left) << worker[i].coe << endl;
	}
}
void short_c(struct work worker[], int len)
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
}//短作业优先
void list_c(struct work worker[], int len)//时间优先
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
	for (int q = 1; q < len; q++)
	{

		for (int v = q + 1; v < len; v++)
		{
			if (worker[q].coe < worker[v].coe)
			{
				work temp;
				temp = worker[q];
				worker[q] = worker[v];
				worker[v] = temp;
			}
		}

	}
}
void com(struct work worker[], int len)
{
	int c;
	cout << "请选择以什么权排序 :" << "\n" << "1、短作业优先" << "\n" << "2、先来先服务" << "\n" << "3、最高响应比" << endl;
	cout << "请输入序号:";
	cin >> c;
	switch (c)
	{
	case 1:  short_c(worker, len); break;
	case 2: list_c(worker, len); break;
	case 3: list_c(worker, len); coe_c(worker, len); break;
	}

}
void main()
{

	
	double i = 1, j = 1;
	int p;
	cout << "请输入作业个数";
	cin >> p;
	work *worker = new work[p];//重点
	work *worker_b = new work[p];	
	for (int a = 0; a < p; a++)
	{
		cout << "请输入" << a + 1 << "号开始时间和运行时间";
		cin >> i >> j;
		worker[a].no = a + 1;
		worker[a].sub = worker[a].start = i;
		worker[a].working = j;
	}
	for (int c = 0; c < p; c++)
	{
		worker_b[c] = worker[c];
	}
	while (i != 0 )
	{
		for (int c = 0; c < p; c++)
		{
			worker[c] = worker_b[c];
		}
		com(worker, p);
		caculate(worker, p);
		show_c(worker, p);
		average(worker, p);
		cout << "是否继续";
		cin >> i;
	}
	delete[]worker;
	delete worker_b;

}
