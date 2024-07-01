#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo c?u trúc thông tin v? thu?c
struct Thuoc {
    char ten[100];
    char hoatChat[100];
    float gia;
    int soLuong;
};

// Hàm in menu chính
void printMenu() {
    printf("\n======== MENU ========");
    printf("\n1. Them thuoc");
    printf("\n2. Xem va cap nhat thuoc");
    printf("\n3. Xoa thuoc");
    printf("\n4. Xem danh sach thuoc");
    printf("\n5. Ban thuoc");
    printf("\n6. Xuat file danh sach thuoc");
    printf("\n7. Tim kiem thuoc");
    printf("\n8. Thoat");
    printf("\n======================");
}

// Hàm thêm thu?c vào danh sách
void themThuoc(struct Thuoc thuoc[], int *n) {
    printf("\nNhap ten thuoc: ");
    getchar(); // Ð?c k? t? newline c?n l?i sau khi nh?p l?a ch?n trý?c ðó
    fgets(thuoc[*n].ten, sizeof(thuoc[*n].ten), stdin);
    thuoc[*n].ten[strcspn(thuoc[*n].ten, "\n")] = 0; // Xóa k? t? newline n?u có

    printf("Nhap hoat chat: ");
    fgets(thuoc[*n].hoatChat, sizeof(thuoc[*n].hoatChat), stdin);
    thuoc[*n].hoatChat[strcspn(thuoc[*n].hoatChat, "\n")] = 0;

    printf("Nhap gia: ");
    scanf("%f", &thuoc[*n].gia);

    printf("Nhap so luong: ");
    scanf("%d", &thuoc[*n].soLuong);

    (*n)++;
}

// Hàm xem danh sách thu?c
void xemThuoc(struct Thuoc thuoc[], int n) {
    if (n == 0) {
        printf("\nDanh sach thuoc rong.");
    } else {
        printf("\nDanh sach thuoc:");
        for (int i = 0; i < n; ++i) {
            printf("\n%d. Ten: %s", i + 1, thuoc[i].ten);
            printf("\n   Hoat chat: %s", thuoc[i].hoatChat);
            printf("\n   Gia: %.2f", thuoc[i].gia);
            printf("\n   So luong: %d", thuoc[i].soLuong);
        }
    }
}

// Hàm c?p nh?t thông tin thu?c
void capNhatThuoc(struct Thuoc thuoc[], int n) {
    int choice;
    printf("\nNhap so thu tu thuoc can cap nhat: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= n) {
        choice--; // Chuy?n v? index trong m?ng
        printf("\nNhap ten thuoc moi: ");
        getchar();
        fgets(thuoc[choice].ten, sizeof(thuoc[choice].ten), stdin);
        thuoc[choice].ten[strcspn(thuoc[choice].ten, "\n")] = 0;

        printf("Nhap hoat chat moi: ");
        fgets(thuoc[choice].hoatChat, sizeof(thuoc[choice].hoatChat), stdin);
        thuoc[choice].hoatChat[strcspn(thuoc[choice].hoatChat, "\n")] = 0;

        printf("Nhap gia moi: ");
        scanf("%f", &thuoc[choice].gia);

        printf("Nhap so luong moi: ");
        scanf("%d", &thuoc[choice].soLuong);

        printf("\nCap nhat thanh cong.");
    } else {
        printf("\nKhong tim thay thuoc can cap nhat.");
    }
}

// Hàm xóa thu?c kh?i danh sách
void xoaThuoc(struct Thuoc thuoc[], int *n) {
    int choice;
    printf("\nNhap so thu tu thuoc can xoa: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= *n) {
        for (int i = choice - 1; i < *n - 1; ++i) {
            thuoc[i] = thuoc[i + 1];
        }
        (*n)--;
        printf("\nXoa thanh cong.");
    } else {
        printf("\nKhong tim thay thuoc can xoa.");
    }
}

// Hàm main
int main() {
    struct Thuoc thuoc[100]; // M?ng ch?a thông tin các lo?i thu?c
    int n = 0; // S? lý?ng thu?c hi?n t?i
    int choice;

    do {
        printMenu();
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themThuoc(thuoc, &n);
                break;
            case 2:
                xemThuoc(thuoc, n);
                capNhatThuoc(thuoc, n);
                break;
            case 3:
                xoaThuoc(thuoc, &n);
                break;
            case 4:
                xemThuoc(thuoc, n);
                break;
            case 8:
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

