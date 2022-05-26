#include<stdio.h>
#include<string.h>
int main() {
	FILE* rf;
	/*rf = fopen("Audi.txt", "w");
	if (rf) {
		fprintf(rf, "%d", 8);
		fprintf(rf, "%d", 9);
	}
	fclose(rf);*/
	char a[100], b;
	int x, y;
	rf = fopen("ANSI.txt", "r");
	/*while (fscanf(rf, "%s", &a) != EOF)
	{
		printf("%s", a);
	}*/
	fscanf(rf, "%s", &a);
	printf("%s", a);
	fclose(rf);
	
}