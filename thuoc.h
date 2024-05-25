#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;
struct Thuoc {
	string TenThuoc;
	int GiaBan;
	string MaSo;
};
void printMenu();
void themThuoc(Thuoc thuoc);
void capNhatThuoc(Thuoc thuoc);
void xoaThuoc(Thuoc thuoc);
void setWindowSize(SHORT width,SHORT height);
