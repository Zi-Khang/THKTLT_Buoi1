#include <stdio.h>
#include <math.h>
#include <limits.h> 
#include <conio.h>

int *timPhanTuLonNhat(int a[], int n) {
	if (n <= 0) return NULL;

	int *maxPtr = &a[0];

	for (int i = 1; i < n; ++i) {
		if (a[i] > *maxPtr) {
			maxPtr = &a[i];
		}
	}

	return maxPtr; 
}


void xuatDiaChiPhanTu(int a[], int n) {
	int *maxChan = NULL; 
	int *minLe = NULL;   

	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) {
			if (maxChan == NULL || a[i] > *maxChan) {
				maxChan = &a[i];
			}
		}
		else {
			if (minLe == NULL || a[i] < *minLe) {
				minLe = &a[i];
			}
		}
	}

	if (maxChan != NULL) {
		printf("Dia chi cua phan tu chan lon nhat: %p\n", (void *)maxChan);
	}
	else {
		printf("Khong co phan tu chan trong mang.\n");
	}

	if (minLe != NULL) {
		printf("Dia chi cua phan tu le nho nhat: %p\n", (void *)minLe);
	}
	else {
		printf("Khong co phan tu le trong mang.\n");
	}
}


int xoaPhanTu(int a[], int *pn) {
	int i, j;

	for (i = 0; i < *pn; ++i) {
		if (a[i] == 0) {
			for (j = i; j < *pn - 1; ++j) {
				a[j] = a[j + 1];
			}
			(*pn)--;
			i--;
		}
	}

	return *pn;
}


void themPhanTu(int a[], int *pn, int x) {
	for (int i = *pn; i > 0; --i) {
		a[i] = a[i - 1];
	}
	a[0] = x; 
	(*pn)++;  
}

int laSoChinhPhuong(int x) {
	int sqrt_x = sqrtf(x);
	return (sqrt_x * sqrt_x == x);
}


int tinhTongSoChinhPhuong(int a[], int n) {
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		if (laSoChinhPhuong(a[i])) {
			sum += a[i];
		}
	}

	return sum;
}

int main() {
	int a[] = { 4, 7, 2, 9, 1, 5, 16 };
	int n = sizeof(a) / sizeof(a[0]);

	
	int *maxPtr = timPhanTuLonNhat(a, n);

	if (maxPtr != NULL) {
		printf("Phan tu lon nhat trong mang: %d\n", *maxPtr);
		printf("Dia chi cua phan tu lon nhat: %p\n", (void *)maxPtr);
	}
	else {
		printf("Mang rong, khong tim thay phan tu lon nhat.\n");
	}

	
	xuatDiaChiPhanTu(a, n);

	
	int new_n = xoaPhanTu(a, &n);

	printf("Mang sau khi xoa phan tu 0:\n");
	for (int i = 0; i < new_n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	
	int x = 10; 
	themPhanTu(a, &new_n, x);

	printf("Mang sau khi them phan tu %d:\n", x);
	for (int i = 0; i < new_n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	
	int sumChinhPhuong = tinhTongSoChinhPhuong(a, new_n);
	printf("Tong cac so chinh phuong trong mang: %d\n", sumChinhPhuong);

	_getch();
}
