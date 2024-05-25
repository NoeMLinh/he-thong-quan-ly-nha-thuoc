#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class shopping {
protected:
    string hotenguoimua;
    float soluong;
public:
    void nhapthongtin() {
        while (getchar() != '\n'); // xoá b? nh? d?m
        cout << "\nHo ten nguoi mua: ";
        getline(cin, hotenguoimua);
        cout << "\nNhap so luong: ";
        cin >> soluong;
    }

    void xuatthongtin() {
        cout << "\nHo ten nguoi mua: " << hotenguoimua;
        cout << "\nSo luong: " << soluong;
    }
};

// Khai báo l?p con
class THUOC1 : public shopping {
public:
    float tinhtienthuoc1() {
        return soluong * 10000; // S?a d? tính ti?n dúng theo s? lu?ng
    }
};

// Khai báo l?p con
class THUOC2 : public shopping {
private:
    string loaithuoc;
public:
    void nhapthongtin() {
        shopping::nhapthongtin();
        while (getchar() != '\n'); // xoá b? nh? d?m
        cout << "\nNhap loai thuoc: ";
        getline(cin, loaithuoc);
    }

    void xuatthongtin() {
        shopping::xuatthongtin();
        cout << "\nLoai thuoc: " << loaithuoc;
    }

    float tinhtienthuoc1() {
        return soluong * 20000; // Gi? s? giá thuoc 1 là 20000
    }
};

// Xu?t t?t c? thông tin
void xuattatcathongtin(THUOC1 ds_thuoc1[], int n, THUOC2 ds_thuoc2[], int m) {
    int dem = 1;
    cout << "\n\n\n\t\t\tDanh sach mua THUOC1: \n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin mua THUOC1: " << dem++ << endl;
        ds_thuoc1[i].xuatthongtin();
        cout << "\nTien THUOC1: " << ds_thuoc1[i].tinhtienthuoc1();
    }

    cout << "\n\n\n\t\tDanh sach mua THUOC2: \n";
    dem = 1;
    for (int i = 0; i < m; i++) {
        cout << "\nThong tin mua THUOC2: " << dem++ << endl;
        ds_thuoc2[i].xuatthongtin();
        cout << "\nTien mua THUOC2: " << ds_thuoc2[i].tinhtienthuoc2();
    }
}

// Hàm qu?n lý
void menu(THUOC1 ds_thuoc1[], int n, THUOC2 ds_thuoc2[], int m) {
    int choice;
    while (true) {
        cout << "\t\t\t\t|_______________________________________|\n";
        cout << "\t\t\t\t|                                       |\n";
        cout << "\t\t\t\t|        Drugstore Main Menu            |\n";
        cout << "\t\t\t\t|                                       |\n";
        cout << "\t\t\t\t|_______________________________________|\n";
        cout << "\t\t\t\t                                        |\n";
        cout << "\t\t\t\t|  1) buy             |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\t\t\t\t|  2) bill            |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\t\t\t\t|  3) Exit            |\n";
        cout << "\t\t\t\t|                     |\n";
        cout << "\n\t\t\t Please select: ";
        cin >> choice;

        if (choice == 1) {
            int chon;
            while (true) {
                system("cls");
                cout << "\n1. thuoc1: ";
                cout << "\n2. thuoc2: ";
                cout << "\n3. Out ";
                cout << "\nBan chon san pham nao: ";
                cin >> chon;

                if (chon == 1) {
                    THUOC1 x;
                    cout << "\n\n\n\t\t\t\tNhap ten thuoc: \n";
                    x.nhapthongtin();
                    ds_thuoc1[n] = x;
                    n++;
                } else if (chon == 2) {
                    SBT x;
                    cout << "\n\n\n\t\t\t\tNhap ten thuoc: \n";
                    x.nhapthongtin();
                    ds_thuoc2[m] = x;
                    m++;
                } else {
                    break;
                }
            }
        } else if (choice == 2) {
            xuattatcathongtin(ds_thuoc1, n, ds_thuoc2, m);
            system("pause");
        } else if (choice == 3) {
            cout << "Het";
            system("pause");
            break;
        }
    }
}

int main() {
    SGK ds_thuoc1[100];
    int n = 0;
    SBT ds_thuoc2[100];
    int m = 0;
    menu(ds_thuoc1, n, ds_thuoc2, m);
    return 0;
}
