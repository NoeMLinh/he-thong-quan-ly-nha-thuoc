#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc cho một loại thuốc
struct Drug {
    int id;
    char name[100];
    float price;
    int quantity;
};

// Khai báo một mảng để lưu trữ các thuốc
struct Drug pharmacy[100];
int drugCount = 0;  // Biến đếm số lượng thuốc hiện có trong danh sách

// Hàm để nhập thông tin cho một loại thuốc mới
void addDrug() {
    struct Drug newDrug;

    printf("Nhập mã số thuốc: ");
    scanf_s("%d", &newDrug.id);
    printf("Nhập tên thuốc: ");
    scanf_s(" %[^\n]s", newDrug.name);
    printf("Nhập giá thuốc: ");
    scanf_s("%f", &newDrug.price);
    printf("Nhập số lượng thuốc: ");
    scanf_s("%d", &newDrug.quantity);

    pharmacy[drugCount++] = newDrug;
    printf("Đã thêm thuốc vào danh sách.\n");
}

// Hàm để tìm kiếm thông tin của một loại thuốc bằng tên
void searchDrugByName(char* name) {
    int found = 0;

    for (int i = 0; i < drugCount; ++i) {
        if (strcmp(pharmacy[i].name, name) == 0) {
            printf("Thông tin thuốc:\n");
            printf("Mã số: %d\n", pharmacy[i].id);
            printf("Tên thuốc: %s\n", pharmacy[i].name);
            printf("Giá thuốc: %.2f\n", pharmacy[i].price);
            printf("Số lượng: %d\n", pharmacy[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm thấy thuốc có tên \"%s\".\n", name);
    }
}

// Hàm để in ra danh sách các thuốc hiện có
void printDrugList() {
    printf("Danh sách thuốc hiện có:\n");
    for (int i = 0; i < drugCount; ++i) {
        printf("%d. %s - Giá: %.2f - Số lượng: %d\n",
            pharmacy[i].id, pharmacy[i].name,
            pharmacy[i].price, pharmacy[i].quantity);
    }
}
// Hàm để xóa thông tin của một loại thuốc bằng tên
void deleteDrugByName(char* name) {
    int found = 0;

    for (int i = 0; i < drugCount; ++i) {
        if (strcmp(pharmacy[i].name, name) == 0) {
            // Di chuyển các phần tử phía sau lên trước để xóa phần tử hiện tại
            for (int j = i; j < drugCount - 1; ++j) {
                pharmacy[j] = pharmacy[j + 1];
            }
            drugCount--;
            printf("Đã xóa thuốc có tên \"%s\" ra khỏi danh sách.\n", name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm thấy thuốc có tên \"%s\" để xóa.\n", name);
    }
}
// Hàm để sửa thông tin của một loại thuốc bằng tên
void updateDrugByName(char* name) {
    int found = 0;

    for (int i = 0; i < drugCount; ++i) {
        if (strcmp(pharmacy[i].name, name) == 0) {
            printf("Nhập thông tin mới cho thuốc \"%s\":\n", name);
            printf("Mã số thuốc: ");
            scanf_s("%d", &pharmacy[i].id);
            printf("Giá thuốc: ");
            scanf_s("%f", &pharmacy[i].price);
            printf("Số lượng thuốc: ");
            scanf_s("%d", &pharmacy[i].quantity);
            printf("Thông tin thuốc đã được cập nhật.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm thấy thuốc có tên \"%s\" để cập nhật.\n", name);
    }
}


int main() {
    int choice;
    char searchName[100], updateName[100], deleteName[100];

    do {
        printf("\nHệ thống quản lí nhà thuốc\n");
        printf("1. Thêm thuốc\n");
        printf("2. Tìm kiếm thuốc\n");
        printf("3. In danh sách thuốc\n");
        printf("4. Xóa thuốc\n");
        printf("5. Sửa thuốc\n");
        printf("0. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addDrug();
            break;
        case 2:
            printf("Nhập tên thuốc cần tìm kiếm: ");
            scanf_s(" %[^\n]s", searchName);
            searchDrugByName(searchName);
            break;
        case 3:
            printDrugList();
            break;
        case 4:
            printf("Nhập tên thuốc cần xóa: ");
            scanf_s(" %[^\n]s", deleteName);
            deleteDrugByName(deleteName);
            break;
        case 5:
            printf("Nhập tên thuốc cần sửa: ");
            scanf_s(" %[^\n]s", updateName);
            updateDrugByName(updateName);
            break;
        case 0:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 0);

    return 0;
}

