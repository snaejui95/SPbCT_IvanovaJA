#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <ctime>
int main()
{
	struct tm* d;
	char date[20];
	const time_t t = time(NULL);
	d = localtime(&t);
	strftime(date, 20, "%d.%m.%Y", d);
	printf("%s\n", d);
	system("pause");
	return 0;
}
