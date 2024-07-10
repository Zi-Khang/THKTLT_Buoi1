#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
	char name[100];
	char gioitinh[20];
	int NgaySinh;
	int ThangSinh;
	int NamSinh;
	printf("Nhap ho ten: ");
	scanf_s("%s", name, 10);
	printf("Nhap gioi tinh: ");
	scanf_s("%s", gioitinh, 10);
	printf("Nhap ngay thang nam sinh: ");
	scanf_s("%d%d%d", &NgaySinh, &ThangSinh, &NamSinh);
	int tuoi = 2024 - NamSinh;
	printf("%s", gioitinh);

	if (gioitinh != "nam" && gioitinh != "nu") 
	{
		printf("101");
	}
	else {
		if (gioitinh == "nam") {
			if (tuoi > 62 || tuoi < 18) {
				printf("errcode");
			}
		}
		if (gioitinh == "nu") {
			if (tuoi > 60 || tuoi < 18) {
				printf("errcode");
			}
		}
	}
	printf("Ten: %s, Gioi tinh: %s, Sinh ngay: %d/%d/%d", name, gioitinh, NgaySinh, ThangSinh, NamSinh);
	printf("So tuoi hien tai: %d", tuoi);
	if (gioitinh == "nam") 
	{
		printf("Ngay nghi huu la : ", ThangSinh, "/" , 2021 + 62 - tuoi);
	}
	if (gioitinh == "nu") {
		printf("Ngay nghi huu la : ", ThangSinh, "/", 2021 + 60 - tuoi);
	}
	_getch();


}