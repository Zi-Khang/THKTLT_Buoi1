#include <stdio.h>
#include <conio.h>

struct PhanSo {
	int tu;
	int mau;
};

void nhapMangPhanSo(struct PhanSo a[], int *n) {
	printf("Nhap so luong phan so: ");
	scanf_s("%d", n);

	for (int i = 0; i < *n; ++i) {
		printf("Nhap phan so thu %d (tu mau): ", i + 1);
		scanf_s("%d %d", &a[i].tu, &a[i].mau);


		while (a[i].mau == 0) {
			printf("Nhap lai mau so khac 0: ");
			scanf_s("%d", &a[i].mau);
		}
	}
}


void xuatMangPhanSo(const struct PhanSo a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d/%d ", a[i].tu, a[i].mau);
	}
	printf("\n");
}


void xuatPhanSoMauLonHonTu(const struct PhanSo a[], int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i].mau > a[i].tu) {
			printf("%d/%d ", a[i].tu, a[i].mau);
		}
	}
	printf("\n");
}

int demPhanSoChan(const struct PhanSo a[], int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].tu % 2 == 0 && a[i].mau % 2 == 0) {
			count++;
		}
	}
	return count;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


void rutGonPhanSo(struct PhanSo *ps) {
	int ucln = gcd(ps->tu, ps->mau);
	ps->tu /= ucln;
	ps->mau /= ucln;
}


struct PhanSo tinhTichMangPhanSo(const struct PhanSo a[], int n) {
	struct PhanSo tich = { 1, 1 };
	for (int i = 0; i < n; ++i) {
		tich.tu *= a[i].tu;
		tich.mau *= a[i].mau;
		rutGonPhanSo(&tich);
	}
	return tich;
}


struct PhanSo timPhanTuLonNhat(const struct PhanSo a[], int n) {
	struct PhanSo maxPhanSo = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i].tu * maxPhanSo.mau > maxPhanSo.tu * a[i].mau) {
			maxPhanSo = a[i];
		}
	}
	return maxPhanSo;
}

int main() {
	struct PhanSo mangPhanSo[100];
	int n;

	nhapMangPhanSo(mangPhanSo, &n);
	xuatMangPhanSo(mangPhanSo, n);

	printf("Cac phan so co mau lon hon tu: ");
	xuatPhanSoMauLonHonTu(mangPhanSo, n);

	printf("So phan so co tu va mau deu chan: %d\n", demPhanSoChan(mangPhanSo, n));

	printf("Tich cac phan so trong mang: ");
	struct PhanSo tich = tinhTichMangPhanSo(mangPhanSo, n);
	printf("%d/%d\n", tich.tu, tich.mau);

	printf("Phan so lon nhat trong mang: ");
	struct PhanSo maxPhanSo = timPhanTuLonNhat(mangPhanSo, n);
	printf("%d/%d\n", maxPhanSo.tu, maxPhanSo.mau);

	_getch();
}
