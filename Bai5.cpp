#include <stdio.h>
#include <conio.h>

void main()
{
	int a, b, c;
	printf("Nhap a: ");
	scanf_s("%d", &a);
	printf("Nhap b: ");
	scanf_s("%d", &b);
	printf("Nhap c: ");
	scanf_s("%d", &c);

	float ketqua = 0;
	ketqua = c / (a - b);
	printf("Ket qua la: %.2f", ketqua);

	_getch();


}