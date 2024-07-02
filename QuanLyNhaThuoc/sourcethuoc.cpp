#include "thuoc.h"
void printMenu(string path) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "            He thong quan ly nha thuoc            " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc moi" << endl;
	cout << "2. Cap nhat thong tin thuoc" << endl;
	cout << "3. Xoa thuoc" << endl;
	cout << "4. Xem danh sach thuoc con lai trong kho" << endl;
	cout << "5. Ban thuoc" << endl;
	cout << "6. Xuat file danh sach thuoc" << endl;
	cout << "7. Tim thuoc" << endl;
	cout << "8. Thoat(thong tin da nhap se duoc luu o " << path << ")" << endl;
	cout << "--------------------------------------------------" << endl;
}
void printMenuBanThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "\n\n\n            He thong quan ly nha thuoc            " << endl;
	cout << "\n\n\n--------------------------------------------------" << endl;
	cout << "\n\n\n1. Ban thuoc" << endl;
	cout << "\n\n\n2. Ban thuoc theo don" << endl;
	cout << "\n\n\n--------------------------------------------------" << endl;
}
void themThuoc(Thuoc &thuoc) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ten thuoc: ";
	cin.ignore(); //Xóa kí tự enter nhận được do lần nhập trước 
	getline(cin, thuoc.TenThuoc); //Nhập tên thuốc
	cout << "Nhap ma so: ";
	cin >> thuoc.MaSo; //Nhập mã số
	cout << "Nhap gia ban: ";
	cin >> thuoc.GiaBan; //Nhập giá bán
	cout << "Nhap so luong thuoc: ";
	cin >> thuoc.soLuongThuoc; //Nhập số lượng thuốc
	cout << "--------------------------------------------------";
}
void capNhatThuoc(Thuoc thuoc[], int n) {
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ma so thuoc can cap nhat: ";
	string maSoCanCapNhat;
	cin >> maSoCanCapNhat; //Nhập mã số cần cập nhật
	bool found = false; //Biến kiểm tra trạng thái tồn tại của mã số cần tìm 
	for (int i = 0; i < n; i++) {
		if (thuoc[i].MaSo.find(maSoCanCapNhat) != string::npos) {
			found = true; //Nếu mã số tồn tại thì found = true
			cout << "Nhap ten thuoc: ";
			cin.ignore();
			getline(cin, thuoc[i].TenThuoc); //Nhập tên thuốc
			cout << "Nhap ma so: ";
			cin >> thuoc[i].MaSo; //Nhập mã số
			cout << "Nhap gia ban: ";
			cin >> thuoc[i].GiaBan; //Nhập giá bán
		}
	}
	if (!found) {
		cout << "Khong tim thay thuoc co ma so " << maSoCanCapNhat << endl; //Nếu không tìm thấy mã số thì thông báo không tìm thấy
	}
	cout << "--------------------------------------------------\n";
	system("pause");	
}
void xemThuoc(Thuoc thuoc[], int n) {
	system("cls");
	for (int i = 0; i < n; i++) { //Duyệt qua từng phần tử trong mảng thuốc
		cout << "--------------------------------------------------" << endl;
		cout << "Ten thuoc: " << thuoc[i].TenThuoc << endl; //Xuất ra tên thuốc
		cout << "Ma so: " << thuoc[i].MaSo << endl; //Xuất ra mã số
		cout << "Gia ban: " << thuoc[i].GiaBan << endl; //Xuất ra giá bán
		cout << "So luong thuoc: " << thuoc[i].soLuongThuoc << endl; //Xuất ra số lượng thuốc
		cout << "--------------------------------------------------\n";
    }
	system("pause");
}
void xemThuoc(Thuoc thuoc) {
	cout << "--------------------------------------------------" << endl;
	cout << "Ten thuoc: " << thuoc.TenThuoc << endl; //Xuất ra tên thuốc
	cout << "Ma so: " << thuoc.MaSo << endl; //Xuất ra mã số
	cout << "Gia ban: " << thuoc.GiaBan << endl; //Xuất ra giá bán
	cout << "So luong thuoc: " << thuoc.soLuongThuoc << endl; //Xuất ra số lượng thuốc
	cout << "--------------------------------------------------\n";
	system("pause");
}
void inDanhSachThuoc(Thuoc thuoc[], int n) {
	system("cls"); //Xóa màn hình
	cout << "--------------------------------------------------" << endl;
	if (n == 0) {
		cout << "Khong co thuoc nao trong kho!" << endl; //Nếu không có thuốc nào trong kho thì thông báo không có thuốc
		cout << "--------------------------------------------------";
		system("pause");
		return;
	}
	for (int i = 0; i < n; i++) { //Duyệt qua từng phần tử trong mảng thuốc
		cout << "Thuoc thu " << i + 1 << endl; //Xuất ra số thứ tự của thuốc
		xemThuoc(thuoc[i]); //Xuất thông tin thuốc
	}
	cout << "--------------------------------------------------\n";
	system("pause");
}
void timThuoc(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	string maSoCanTim; //Biến lưu mã số cần tìm
	cout << "Nhap ma so thuoc can tim: "; 
	cin.ignore();
	getline(cin, maSoCanTim); //Nhập mã số cần tìm
	bool timThay = false; //Biến kiểm tra trạng thái tìm thấy
	for (int i = 0; i < n; i++) {
		if (thuoc[i].MaSo.find(maSoCanTim) != string::npos) { //Nếu mã số cần tìm tồn tại trong mảng
			xemThuoc(thuoc[i]); //Xuất thông tin thuốc
			timThay = true; //Đặt trạng thái tìm thấy thành true
		}
	}
	if (!timThay) {
		cout << "Khong tim thay thuoc co ma so " << maSoCanTim << endl; //Nếu không tìm thấy mã số thì thông báo không tìm thấy
		cout << "--------------------------------------------------\n";
	}
	system("pause");
}
void xoaThuoc(Thuoc thuoc[], int &soLuongThuoc) { 
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ma so thuoc can xoa: ";
	string maSoCanXoa; //Biến lưu mã số cần xóa
	cin.ignore();
	getline(cin, maSoCanXoa); //Nhập mã số cần xóa
	for (int i = 0; i < soLuongThuoc; i++) {
		if (thuoc[i].MaSo == maSoCanXoa) {
			for (int j = i; j < soLuongThuoc - 1; j++) {
				thuoc[j] = thuoc[j + 1]; //Dịch chuyển các phần tử sau phần tử cần xóa lên 1 bước
			}
			--soLuongThuoc; //Giảm số lượng thuốc đi 1
			cout << "Xoa thanh cong!" << endl; //Thông báo xóa thành công
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay thuoc co ma so " << maSoCanXoa << endl; //Nếu không tìm thấy mã số thì thông báo không tìm thấy
	cout << "--------------------------------------------------\n";
	system("pause");
}
void banThuocNgoai(Thuoc thuoc[], int n) {
	cout << "--------------------------------------------------" << endl;
	int x = 0;
	char a = 'y'; //Biến kiểm tra trạng thái tiếp tục mua thuốc
	Thuoc banThanhCong[100]; //Mảng lưu thông tin thuốc đã bán thành công 
	do {
		cout << "Nhap ten thuoc can ban: ";
		string tenThuocCanBan; //Biến lưu tên thuốc cần bán
		cin.ignore();
		getline(cin, tenThuocCanBan); //Nhập tên thuốc cần bán
		for (int i = 0; i < n; i++) {
			if (thuoc[i].TenThuoc == tenThuocCanBan) { //Nếu tên thuốc cần bán tồn tại trong kho
				cout << "Nhap so luong thuoc can ban: ";
				int soLuongCanBan; //Biến lưu số lượng thuốc cần bán
				cin >> soLuongCanBan; //Nhập số lượng thuốc cần bán
				if (soLuongCanBan > thuoc[i].soLuongThuoc) { //Nếu số lượng thuốc cần bán lớn hơn số lượng thuốc trong kho
					cout << "So luong thuoc trong kho khong du de ban!" << endl; //Thông báo số lượng thuốc không đủ để bán
				}
				else {
					thuoc[i].soLuongThuoc -= soLuongCanBan; //Giảm số lượng thuốc trong kho đi số lượng thuốc đã bán
					int giaBan = thuoc[i].GiaBan * soLuongCanBan; //Tính giá bán
					cout << "Tong tien: " << giaBan << endl; //Xuất ra tổng tiền
					banThanhCong[x].TenThuoc = thuoc[i].TenThuoc; //Lưu thông tin thuốc đã bán thành công
					banThanhCong[x].GiaBan = giaBan; //Lưu số tiền bán được
					x++; //Tăng số lượng thuốc đã bán thành công
				}
			}
		}
		cout << "Ban co muon mua them thuoc khong? (y/n): ";
		cin >> a; //Nhập lựa chọn tiếp tục mua thuốc
	} while (a == 'y');
	cout << "Ban co muon xuat file hoa don khong? (y/n): "; 
	char c;
	cin >> c; //Nhập lựa chọn xuất file hoá đơn
	if (c == 'y') {
		ofstream file; //Mở file
		string path = "C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls"; //Đường dẫn file hoá đơn
		file.open("C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls"); //Mở file
		file << "Hoa don ban thuoc" << endl; //In ra tiêu đề hoá đơn
		file << "Ten thuoc\tGia ban" << endl; //In ra tiêu đề cột
		for (int i = 0; i < x; i++) {
			file << banThanhCong[i].TenThuoc << "\t" << banThanhCong[i].GiaBan << endl; //In ra thông tin thuốc đã bán thành công
		}
		cout << "Xuat file thanh cong!" << endl; //Thông báo xuất file thành công
		cout << "File duoc luu tai: " << path << endl; //Thông báo đường dẫn file
		file.close(); //Đóng file
	}
	cout << "--------------------------------------------------\n";
	system("pause");
}
void banThuocTheoDon(Thuoc thuoc[], int n) {
	system("cls");
	string path; //Biến lưu đường dẫn file đơn thuốc
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap duong dan den file don thuoc(bo dau ngoac kep hai dau duong dan): "; 
	cin >> path; //Nhập đường dẫn file
	ifstream file;
	file.open(path); //Mở file
	int soThuocCanMua; //Biến lưu số lượng thuốc cần mua
	file >> soThuocCanMua; //Đọc số lượng thuốc cần mua
	Thuoc *muaThuoc = new Thuoc[soThuocCanMua]; //Mảng lưu thông tin thuốc cần mua
	string *line = new string[soThuocCanMua]; //Mảng lưu thông tin thuốc từ file
	int x = 0; //Biến lưu số lượng thuốc đã bán thành công
	Thuoc banThanhCong[100]; //Mảng lưu thông tin thuốc đã bán thành công
	for (int i = 0; i < soThuocCanMua; i++) { //Duyệt qua từng phần tử trong mảng thuốc cần mua
		file >> line[i]; //Đọc thông tin thuốc từ file
		tachDauPhayBanThuoc(line[i], muaThuoc[i]); //Tách thông tin thuốc từ file
	}
	for (int a = 0; a < soThuocCanMua; a++) {
		bool timThay = false; //Biến kiểm tra trạng thái tìm thấy
		for (int b = 0; b < n; b++) { //Duyệt qua từng phần tử trong mảng thuốc
			if (muaThuoc[a].TenThuoc == thuoc[b].TenThuoc) {
				timThay = true; //Nếu tên thuốc cần mua tồn tại trong kho thì timThay = true
				if (muaThuoc[a].soLuongThuoc > thuoc[b].soLuongThuoc) {
					cout << "So luong thuoc " << muaThuoc[a].TenThuoc << " trong kho khong du de ban!" << endl; //Thông báo số lượng thuốc không đủ để bán
				}
				else {
					thuoc[b].soLuongThuoc -= muaThuoc[a].soLuongThuoc; //Giảm số lượng thuốc trong kho đi số lượng thuốc đã bán
					int giaBan = muaThuoc[a].soLuongThuoc * thuoc[b].GiaBan; //Tính giá bán
					cout << "Ten thuoc: " << muaThuoc[a].TenThuoc << endl; //Xuất ra tên thuốc
					cout << "Tong tien: " << giaBan << endl; //Xuất ra tổng tiền
					banThanhCong[x] = muaThuoc[a]; //Lưu thông tin thuốc đã bán thành công
					x++; //Tăng số lượng thuốc đã bán thành công
					continue;
				}
			} else {
				timThay = false; //Nếu tên thuốc cần mua không tồn tại trong kho thì timThay = false
			}
		}
		if (!timThay) {
			cout << "Khong tim thay thuoc " << muaThuoc[a].TenThuoc << " trong kho!" << endl; //Thông báo không tìm thấy thuốc
		}
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Ban co muon xuat file hoa don khong? (y/n): "; 
	char c; //Biến lưu lựa chọn xuất file hoá đơn
	cin >> c; //Nhập lựa chọn xuất file hoá đơn
	if (c == 'y') {
		ofstream file; //Mở file
		string path = "C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls"; //Đường dẫn file hoá đơn
		file.open("C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls"); //Mở file
		file << "Hoa don ban thuoc" << endl; //In ra tiêu đề hoá đơn
		file << "Ten thuoc\tSo luong\tGia ban" << endl; //In ra tiêu đề cột
		for (int i = 0; i < x; i++) {
			file << muaThuoc[i].TenThuoc << "\t" << muaThuoc[i].soLuongThuoc << "\t" << muaThuoc[i].soLuongThuoc * thuoc[i].GiaBan << endl; //In ra thông tin thuốc đã bán thành công
		}
		cout << "Xuat file thanh cong!" << endl; //Thông báo xuất file thành công
		cout << "File duoc luu tai: " << path << endl; //Thông báo đường dẫn file
		cout << "--------------------------------------------------\n" << endl;
		file.close();
	}
	file.close();
	delete [] muaThuoc;
	delete [] line;
	system("pause");
}
void xuatFileDS(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	ofstream file; //Mở file
	string path = "C:\\Users\\admin\\Documents\\DanhSachThuoc.xls"; //Đường dẫn file danh sách thuốc
	file.open("C:\\Users\\admin\\Documents\\DanhSachThuoc.xls"); //Mở file
	file << "Danh sach thuoc trong kho" << endl; //In ra tiêu đề danh sách thuốc
	file << "Ten thuoc\tMa so\tGia ban\tSo luong" << endl; //In ra tiêu đề cột
	for (int i = 0; i < n; i++) {
		file << thuoc[i].TenThuoc << "\t*" << thuoc[i].MaSo << "\t" << thuoc[i].GiaBan << "\t" << thuoc[i].soLuongThuoc << endl; //In ra thông tin thuốc
	}
	cout << "Xuat file thanh cong!" << endl; //Thông báo xuất file thành công
	cout << "File duoc luu tai: " << path << endl; //Thông báo đường dẫn file
	cout << "--------------------------------------------------" << endl;
	file.close();
	system("pause");
}
void printMenuTimThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "\n\n1. Tim thuoc theo ten" << endl;
	cout << "\n\n2. Tim thuoc theo ma so" << endl;
	cout << "--------------------------------------------------" << endl;
}
void timThuocTheoTen(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	string tenThuocCanTim; //Biến lưu tên thuốc cần tìm
	cout << "Nhap ten thuoc can tim: ";
	cin.ignore();
	getline(cin, tenThuocCanTim); //Nhập tên thuốc cần tìm
	for (int i = 0; i < n; i++) {
		if (thuoc[i].TenThuoc.find(tenThuocCanTim) != string::npos) { //Nếu tên thuốc cần tìm tồn tại trong mảng
			xemThuoc(thuoc[i]); //Xuất thông tin thuốc
		}
	}
    cout << "--------------------------------------------------";
	system("pause");
}
void menuThemThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc tu ban phim" << endl;
	cout << "2. Them thuoc tu file" << endl;
	cout << "--------------------------------------------------" << endl;
}
void menuThoat() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "1. Luu va thoat" << endl;
	cout << "2. Thoat" << endl;
	cout << "--------------------------------------------------" << endl;
}
void tachDauPhay(string s, Thuoc &thuoc) {
	char arr[100]; //Mảng lưu các kí tự trong chuỗi được tách ra sau khi bỏ dấu phẩy 
	string arr2[4]; //Mảng lưu thông tin thuốc sau khi tách dấu phẩy
	int x = s.length(); //Độ dài chuỗi
	for (int i = 0; i < x; i++) { //Duyệt qua từng kí tự trong chuỗi
		arr[i] = s[i]; //Gán kí tự vào mảng arr
	}
	int a = 0; //Biến đếm số lượng phần tử giữa các dấu phẩy
	for (int i = 0; i < x; i++) {
		if (arr[i] == ',') { //Nếu gặp dấu phẩy
			a++; //Tăng biến đếm lên 1
			continue; //Bỏ qua kí tự dấu phẩy
		}
		arr2[a] += arr[i]; //Gán kí tự vào mảng arr2
	}
	thuoc.TenThuoc = arr2[0]; //Gán tên thuốc
	thuoc.MaSo = arr2[1]; //Gán mã số
	thuoc.GiaBan = stoi(arr2[2]); //Gán giá bán
	thuoc.soLuongThuoc = stoi(arr2[3]); //Gán số lượng thuốc
}
void tachDauPhayBanThuoc(string s, Thuoc &thuoc) {
	char arr[100]; //Mảng lưu các kí tự trong chuỗi được tách ra sau khi bỏ dấu phẩy
	string arr2[2]; //Mảng lưu thông tin thuốc sau khi tách dấu phẩy
	int x = s.length(); //Độ dài chuỗi
	for (int i = 0; i < x; i++) {
		arr[i] = s[i]; //Gán kí tự vào mảng arr
	}
	int a = 0; //Biến đếm số lượng phần tử giữa các dấu phẩy 
	for (int i = 0; i < x; i++) { //Duyệt qua từng kí tự trong chuỗi
		if (arr[i] == ',') { //Nếu gặp dấu phẩy
			a++; //Tăng biến đếm lên 1
			continue; //Bỏ qua kí tự dấu phẩy
		}
		arr2[a] += arr[i]; //Gán kí tự vào mảng arr2
	}
	thuoc.TenThuoc = arr2[0]; //Gán tên thuốc
	thuoc.soLuongThuoc = stoi(arr2[1]); //Gán số lượng thuốc
}