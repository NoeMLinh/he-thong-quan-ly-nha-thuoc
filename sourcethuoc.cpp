#include "thuoc.h"
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void printMenu() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "            He thong quan ly nha thuoc            " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc moi" << endl;
	cout << "2. Cap nhat thong tin thuoc" << endl;
	cout << "3. Xoa thuoc" << endl;
	cout << "4. Xem danh sach thuoc con lai trong kho" << endl;
	cout << "5. Don thuoc mau theo benh" << endl;
	cout << "6. Xem thuoc da nhap" << endl;
	cout << "7. Thoat" << endl;
	cout << "--------------------------------------------------" << endl;
}
void themThuoc(Thuoc thuoc) {
	system("cls");
	cout << "Nhap ten thuoc: ";
	cin.ignore();
	getline(cin, thuoc.TenThuoc);
	cout << "Nhap ma so: ";
	cin.ignore();
	getline(cin, thuoc.MaSo);
	cout << "Nhap gia ban: ";
	cin >> thuoc.GiaBan;
}
void capNhatThuoc(Thuoc thuoc) {
	system("cls");
	cout << "Nhap ten thuoc: ";
	cin.ignore();
	getline(cin, thuoc.TenThuoc);
	cout << "Nhap ma so: ";
	cin.ignore();
	getline(cin, thuoc.MaSo);
	cout << "Nhap gia ban: ";
	cin >> thuoc.GiaBan;
}