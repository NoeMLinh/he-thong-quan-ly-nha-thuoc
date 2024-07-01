#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for drug information
struct Thuoc {
    char TenThuoc[100];
    char MaSo[20];
    float GiaBan;
    int soLuongThuoc;
};

// Function prototypes
void printMenu();
void printMenuBanThuoc();
void themThuoc(struct Thuoc *thuoc);
void capNhatThuoc(struct Thuoc thuoc[], int n);
void xemThuoc(struct Thuoc thuoc[], int n);
void xemThuocSingle(struct Thuoc thuoc);
void inDanhSachThuoc(struct Thuoc thuoc[], int n);
void timThuoc(struct Thuoc thuoc[], int n);
void xoaThuoc(struct Thuoc thuoc[], int *soLuongThuoc);
void banThuocNgoai(struct Thuoc thuoc[], int n);
void banThuocTheoDon(struct Thuoc thuoc[], int n);
void xuatFileDS(struct Thuoc thuoc[], int n);
void printMenuTimThuoc();
void timThuocTheoTen(struct Thuoc thuoc[], int n);
struct Thuoc tachPhanTuTuFile(char path[]);
void menuThemThuoc();

// Function to set console window size (for Windows only)
void SetWindowSize(SHORT width, SHORT height) {
    // Not implemented in C, requires Windows API which is C++ specific
}

// Function to print the main menu
void printMenu() {
    system("cls");
    printf("--------------------------------------------------\n");
    printf("            He thong quan ly nha thuoc            \n");
    printf("--------------------------------------------------\n");
    printf("1. Them thuoc moi\n");
    printf("2. Cap nhat thong tin thuoc\n");
    printf("3. Xoa thuoc\n");
    printf("4. Xem danh sach thuoc con lai trong kho\n");
    printf("5. Ban thuoc\n");
    printf("6. Xuat file danh sach thuoc\n");
    printf("7. Tim thuoc\n");
    printf("8. Thoat\n");
    printf("--------------------------------------------------\n");
}

// Function to print the menu for selling drugs
void printMenuBanThuoc() {
    system("cls");
    printf("--------------------------------------------------\n");
    printf("\n\n\n            He thong quan ly nha thuoc            \n");
    printf("\n\n\n--------------------------------------------------\n");
    printf("\n\n\n1. Ban thuoc\n");
    printf("\n\n\n2. Ban thuoc theo don\n");
    printf("\n\n\n--------------------------------------------------\n");
}

// Function to add a new drug
void themThuoc(struct Thuoc *thuoc) {
    system("cls");
    printf("--------------------------------------------------\n");
    printf("Nhap ten thuoc: ");
    getchar(); // Clear input buffer
    fgets(thuoc->TenThuoc, sizeof(thuoc->TenThuoc), stdin);
    thuoc->TenThuoc[strcspn(thuoc->TenThuoc, "\n")] = 0;

    printf("Nhap ma so: ");
    fgets(thuoc->MaSo, sizeof(thuoc->MaSo), stdin);
    thuoc->MaSo[strcspn(thuoc->MaSo, "\n")] = 0;

    printf("Nhap gia ban: ");
    scanf("%f", &thuoc->GiaBan);

    printf("Nhap so luong thuoc: ");
    scanf("%d", &thuoc->soLuongThuoc);

    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to update drug information
void capNhatThuoc(struct Thuoc thuoc[], int n) {
    printf("--------------------------------------------------\n");
    printf("Nhap ma so thuoc can cap nhat: ");
    char maSoCanCapNhat[20];
    scanf("%s", maSoCanCapNhat);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(thuoc[i].MaSo, maSoCanCapNhat) == 0) {
            found = 1;
            printf("Nhap ten thuoc: ");
            getchar(); // Clear input buffer
            fgets(thuoc[i].TenThuoc, sizeof(thuoc[i].TenThuoc), stdin);
            thuoc[i].TenThuoc[strcspn(thuoc[i].TenThuoc, "\n")] = 0;

            printf("Nhap ma so: ");
            fgets(thuoc[i].MaSo, sizeof(thuoc[i].MaSo), stdin);
            thuoc[i].MaSo[strcspn(thuoc[i].MaSo, "\n")] = 0;

            printf("Nhap gia ban: ");
            scanf("%f", &thuoc[i].GiaBan);

            printf("Cap nhat thanh cong.\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay thuoc co ma so %s\n", maSoCanCapNhat);
    }
    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to display all drugs
void xemThuoc(struct Thuoc thuoc[], int n) {
    system("cls");
    for (int i = 0; i < n; i++) {
        printf("--------------------------------------------------\n");
        printf("Ten thuoc: %s\n", thuoc[i].TenThuoc);
        printf("Ma so: %s\n", thuoc[i].MaSo);
        printf("Gia ban: %.2f\n", thuoc[i].GiaBan);
        printf("So luong thuoc: %d\n", thuoc[i].soLuongThuoc);
        printf("--------------------------------------------------\n");
    }
    system("pause");
}

// Function to display a single drug
void xemThuocSingle(struct Thuoc thuoc) {
    printf("--------------------------------------------------\n");
    printf("Ten thuoc: %s\n", thuoc.TenThuoc);
    printf("Ma so: %s\n", thuoc.MaSo);
    printf("Gia ban: %.2f\n", thuoc.GiaBan);
    printf("So luong thuoc: %d\n", thuoc.soLuongThuoc);
    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to print the list of drugs
void inDanhSachThuoc(struct Thuoc thuoc[], int n) {
    system("cls");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Thuoc thu %d\n", i + 1);
        xemThuocSingle(thuoc[i]);
    }
    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to search for a drug by name or code
void timThuoc(struct Thuoc thuoc[], int n) {
    system("cls");
    printf("--------------------------------------------------\n");
    char maSoCanTim[20];
    printf("Nhap ma so thuoc can tim: ");
    scanf("%s", maSoCanTim);

    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(thuoc[i].MaSo, maSoCanTim) == 0) {
            xemThuocSingle(thuoc[i]);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay thuoc co ma so %s\n", maSoCanTim);
    }
    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to delete a drug
void xoaThuoc(struct Thuoc thuoc[], int *soLuongThuoc) {
    system("cls");
    printf("--------------------------------------------------\n");
    char maSoCanXoa[20];
    printf("Nhap ma so thuoc can xoa: ");
    scanf("%s", maSoCanXoa);

    for (int i = 0; i < *soLuongThuoc; i++) {
        if (strcmp(thuoc[i].MaSo, maSoCanXoa) == 0) {
            for (int j = i; j < *soLuongThuoc - 1; j++) {
                thuoc[j] = thuoc[j + 1];
            }
            (*soLuongThuoc)--;
            printf("Xoa thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay thuoc co ma so %s\n", maSoCanXoa);
    printf("--------------------------------------------------\n");
    system("pause");
}

// Function to sell drugs externally
void banThuocNgoai(struct Thuoc thuoc[], int n) {
    system("cls");
    printf("--------------------------------------------------\n");
    char tenThuocCanBan[100];
    printf("Nhap ten thuoc can ban: ");
    getchar(); // Clear input buffer
    fgets(tenThuocCanBan, sizeof(tenThuocCanBan), stdin);
    tenThuocCanBan[strcspn(tenThuocCanBan, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(thuoc[i].TenThuoc

