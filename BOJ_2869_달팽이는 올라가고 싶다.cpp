#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int a, b, v;//a��ŭ �ö󰡼� b��ŭ ��������.
	scanf("%d %d %d", &a, &b, &v);	
	int vmaANDtmp = v - a;
	int amb = a - b;

	if (vmaANDtmp % amb != 0)
		vmaANDtmp = (vmaANDtmp / amb + 1) * amb;

	printf("%d\n", vmaANDtmp / amb + 1);
}