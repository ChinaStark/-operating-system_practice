#include<iostream>
using namespace std;
void w(struct worker work[], int len);
void s(struct worker work[], int len);
struct worker
{
	double start;
	double end;
};

int  main()
{
	struct worker wortk[2];
	w(wortk,2);
	s(wortk,2);
	return 0;
	
}
void w(struct worker work[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int x, y;
		cin >> x >> y;
		work[i].start = x;
		work[i].end = y;
	}
}
void s(struct worker work[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << work[i].start << "   " << work[i].end << endl;
	}
}