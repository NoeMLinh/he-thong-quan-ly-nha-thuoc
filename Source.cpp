#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <math.h>
#include "thuoc.h"
using namespace std;

int main() {
	Thuoc thuoc[50]; // Khai bao mang chua cac thuoc
	int Gia, Lai, Thue;
	int choice;
	int n=0;
	string maSoCanTim;
	do {
		printMenu();
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		switch (choice) {
		case 1:
			themThuoc(thuoc[n]);
			n++;
			int a;
			cin >> a;
			break;
		case 2:
			capNhatThuoc(thuoc[n]);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Nhap ma so thuoc can xem: ";
			cin.ignore();
			getline(cin, maSoCanTim);
			for (int i=0; i<n; i++) {
				if (thuoc[i].MaSo == maSoCanTim) {
					cout << "Ten thuoc: " << thuoc[i].TenThuoc << endl;
					cout << "Ma so: " << thuoc[i].MaSo << endl;
					cout << "Gia ban: " << thuoc[i].GiaBan << endl;
				}
			}
			break;
		case 7:
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			break;
		}
	} while (choice != 7);
	return 0;
}