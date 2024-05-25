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
class SGK : public shopping {
public:
    float tinhtienmuasgk() {
        return soluong * 10000; // S?a d? tính ti?n dúng theo s? lu?ng
    }
};

// Khai báo l?p con
class SBT : public shopping {
private:
    string loaisach;
public:
    void nhapthongtin() {
        shopping::nhapthongtin();
        while (getchar() != '\n'); // xoá b? nh? d?m
        cout << "\nNhap loai sach: ";
        getline(cin, loaisach);
    }

    void xuatthongtin() {
        shopping::xuatthongtin();
        cout << "\nLoai sach: " << loaisach;
    }

    float tinhtienmuasbt() {
        return soluong * 20000; // Gi? s? giá sách bài t?p là 20000
    }
};

// Xu?t t?t c? thông tin
void xuattatcathongtin(SGK ds_sgk[], int n, SBT ds_sbt[], int m) {
    int dem = 1;
    cout << "\n\n\n\t\t\tDanh sach mua SGK: \n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin mua SGK: " << dem++ << endl;
        ds_sgk[i].xuatthongtin();
        cout << "\nTien SGK: " << ds_sgk[i].tinhtienmuasgk();
    }

    cout << "\n\n\n\t\tDanh sach mua SBT: \n";
    dem = 1;
    for (int i = 0; i < m; i++) {
        cout << "\nThong tin mua SBT: " << dem++ << endl;
        ds_sbt[i].xuatthongtin();
        cout << "\nTien mua SBT: " << ds_sbt[i].tinhtienmuasbt();
    }
}

// Hàm qu?n lý
void menu(SGK ds_sgk[], int &n, SBT ds_sbt[], int &m) {
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
                cout << "\n1. Sach giao khoa: ";
                cout << "\n2. Sach bai tap: ";
                cout << "\n3. Out ";
                cout << "\nBan chon san pham nao: ";
                cin >> chon;

                if (chon == 1) {
                    SGK x;
                    cout << "\n\n\n\t\t\t\tNhap sach: \n";
                    x.nhapthongtin();
                    ds_sgk[n] = x;
                    n++;
                } else if (chon == 2) {
                    SBT x;
                    cout << "\n\n\n\t\t\t\tNhap sach: \n";
                    x.nhapthongtin();
                    ds_sbt[m] = x;
                    m++;
                } else {
                    break;
                }
            }
        } else if (choice == 2) {
            xuattatcathongtin(ds_sgk, n, ds_sbt, m);
            system("pause");
        } else if (choice == 3) {
            cout << "Het";
            system("pause");
            break;
        }
    }
}

int main() {
    SGK ds_sgk[100];
    int n = 0;
    SBT ds_sbt[100];
    int m = 0;
    menu(ds_sgk, n, ds_sbt, m);
    return 0;
}
