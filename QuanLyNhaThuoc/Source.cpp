#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include "thuoc.h"
using namespace std;

int main() {
	Thuoc thuoc[100]; // Khai báo mảng thuốc có tối đa 100 phần tử
	int n = 0; // Biến n lưu số lượng thuốc hiện có
	string path = "C:\\Users\\admin\\Documents\\database.txt"; //Đường dẫn file database.txt
	int choice;
	do {
		printMenu(path); // In ra menu chính
		cout << "Nhap lua chon cua ban: ";
		cin >> choice; // Nhập lựa chọn từ bàn phím
		switch (choice) { // Xử lý lựa chọn
		case 1:
			menuThemThuoc(); // In ra menu thêm thuốc
			int choice1; // Biến lựa chọn cho menu thêm thuốc
			cout << "Nhap lua chon cua ban: ";
			cin >> choice1; // Nhập lựa chọn từ bàn phím
			switch (choice1) { // Xử lý lựa chọn
			case 1:
			{
				char c; // Biến c lưu lựa chọn của người dùng
				do {
					themThuoc(thuoc[n]); // Thêm thuốc vào mảng thuốc
					n++;
					cout << "\nBan co muon nhap them thuoc khong? (y/n): ";
					cin >> c; // Nhập lựa chọn từ bàn phím
				} while (c == 'y');
				break;
			}
			case 2:
			{
				system("cls");
				string path1;
				cout << "File don thuoc co dinh dang nhu sau: " << endl;
				cout << "(So loai thuoc can nhap kho)" << endl << "(Ten thuoc),(Ma so),(Gia ban),(So luong)" << endl;
				cout << "Vi du: " << endl;
				cout << "3" << endl;
				cout << "Thuoc1,MS1,10000,10" << endl;
				cout << "Thuoc2,MS2,20000,20" << endl;
				cout << "Thuoc3,MS3,30000,30" << endl; //Định dạng file đơn thuốc 
				cout << "Nhap duong dan file(bo dau ngoac kep hai dau duong dan): ";
				cin >> path1; //Nhập đường dẫn file
				ifstream file; 
				file.open(path1); //Mở file
				int x;
				file >> x; //Đọc số lượng thuốc cần nhập
				string lineThuoc; //Biến lineThuoc lưu thông tin thuốc
				for (int i = 0; i < x; i++) {
					file >> lineThuoc;
					tachDauPhay(lineThuoc, thuoc[n+i]); //Tách thông tin thuốc từ file
				}
				n += x; //Cập nhật số lượng thuốc
				file.close(); //Đóng file
				cout << "Nhap thanh cong!" << endl;
				break;
			}
			default:
				cout << "Lua chon khong hop le." << endl;
				break;
			}
			system("pause"); //Dừng màn hình
			break;
		case 2:
			xemThuoc(thuoc, n); //Xem danh sách thuốc
			capNhatThuoc(thuoc, n); //Cập nhật thông tin thuốc
			break;
		case 3:
			xoaThuoc(thuoc, n); //Xóa thuốc
			break;
		case 4:
			xemThuoc(thuoc, n); //Xem danh sách thuốc
			break;
		case 5:
			printMenuBanThuoc(); //In ra menu bán thuốc
			int choiceBanThuoc; //Biến lựa chọn cho menu bán thuốc
			cout << "Nhap lua chon cua ban: ";
			cin >> choiceBanThuoc; //Nhập lựa chọn từ bàn phím
			switch (choiceBanThuoc) { //Xử lý lựa chọn
			case 1:
				xemThuoc(thuoc, n); //Xem danh sách thuốc
				banThuocNgoai(thuoc, n); //Bán thuốc nhập tay thủ công từ bàn phím
				break;
			case 2:
				banThuocTheoDon(thuoc, n); //Bán thuốc theo file đơn thuốc 
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			}
			break;
		case 6:
			xuatFileDS(thuoc, n); //Xuất danh sách thuốc ra file excel
			break;
		case 7:
			int choiceTim; //Biến lựa chọn cho menu tìm kiếm thuốc
			printMenuTimThuoc(); //In ra menu tìm kiếm thuốc
			cout << "\nNhap lua chon cua ban: ";
			cin >> choiceTim; //Nhập lựa chọn từ bàn phím
			switch (choiceTim) { //Xử lý lựa chọn
			case 1:
				timThuocTheoTen(thuoc, n); //Tìm kiếm thuốc theo tên
				break;
			case 2:
				timThuoc(thuoc, n); //Tìm kiếm thuốc theo mã số
				break;
			default:
				cout << "\nLua chon khong hop le." << endl;
			}
			break;
		case 8:
		{
			system("cls"); //Xóa màn hình
			cout << "--------------------------------------------------" << endl;
			ofstream file; //Khai báo biến file
			file.open("C:\\Users\\admin\\Documents\\DanhSachThuoc.txt"); //Tạo file DanhSachThuoc.txt
			file << n << endl; //Ghi số lượng thuốc vào file
			for (int i = 0; i < n; i++) {
				file << thuoc[i].TenThuoc << "," << thuoc[i].MaSo << "," << thuoc[i].GiaBan << "," << thuoc[i].soLuongThuoc << endl; //Ghi thông tin thuốc vào file theo đúng định dạng
			}
			file.close(); //Đóng file
			exit(0); //Thoát chương trình
			break;
		}
		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			system("pause");
			printMenu(path); 
			cout << "Nhap lua chon cua ban: ";
			cin >> choice; //Nhập lại lựa chọn từ bàn phím
			break;
		}
	} while (choice != 9);
	return 0;
}