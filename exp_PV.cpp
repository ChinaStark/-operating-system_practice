#include <iostream>
#include<iomanip>
using namespace std;
int v = 0;//ѭ���ؼ�
int le = 0;//���鳤��
int b;//ʱ��Ƭ
struct Progress
{
	char a[5];
	int NO;//���ȼ�
	int w_time;//����Ҫ����ʱ��
	int w;
	int hour = 0 ;//�Ѿ�����ʱ��
	char statu = 'W';//����״̬
	int a_time;//����ʱ��
};
void ADD(struct Progress A[] ,int len)
{
	cout << "���������ȼ�����Ҫʱ�䡡����ʱ�䡡";
	cin >> A[len].NO >> A[len].w_time >> A[len].a_time;
	cout << "����ҵȡ����ҵ�����ְɣ�";
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
		A[0].statu = 'R';//�Խ����ı�־λ����
	for (int i = 0; i < len; i++)
	{
		cout << setw(10) << setiosflags(ios::left)<<A[i].a<< setw(10) << setiosflags(ios::left) << A[i].NO << setw(10) << setiosflags(ios::left) << A[i].a_time << setw(10) << setiosflags(ios::left) << A[i].w_time << setw(10) << setiosflags(ios::left) << A[i].hour << setw(10) << setiosflags(ios::left) << A[i].statu << endl;
	}
	A[0].statu = 'W';
}
void main()
{
	Progress working[6];
	int time = 0;//ʱ��
	int a;
	
	int c = 0;//������
	cout << "������ʱ��Ƭ��С��";
	cin >> b;
	int p = 1;
	while (p)
	{
		cout << " 1�����������ӽ���\n" << " 2��������Ǵ�ӡ����\n" << " 3��������ǽ����˳�����\n" << "���������";
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
				if(working[0].a_time>time)//��ֹδ����ִ��
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
					v = 1;//��������ı�־λ
				cout << "��ҵ���� " << "��ҵ���ȼ� " << "����ʱ�� " << "����ʱ�� " << "����ʱ�� " << "����״̬ " << endl;
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