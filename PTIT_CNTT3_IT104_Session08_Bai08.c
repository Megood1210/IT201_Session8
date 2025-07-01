#include <stdio.h>
#define MAX_LENGTH 1000
// Hàm lấy số lượng phần tử của mảng
int inputSize() {
    int n;
    do {
        printf("Nhap so luong phan tu cua mang : ");
        scanf("%d", &n);
    } while (n <= 0 || n >= MAX_LENGTH);
    return n;
}
// Nhập các phần tử vào trong mảng
void inputArray(int array[], int totalElement) {
    printf("Nhap cac phan tu vao mang: \n");
    for (int i = 0; i < totalElement; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &array[i]);
    }
}
// In ra các phần tử của mảng
void printArray(int array[], int totalElement) {
    for (int i = 0; i < totalElement; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// Hàm sắp xếp mảng theo thuật toán sắp xếp chèn (Insertion Sort)
void insertionSort(int array[], int totalElement) {
    for (int i = 1; i < totalElement; i++) {
        int key = array[i];
        int j = i - 1;
        // Di chuyển các phần tử của array[0..i-1], mà lớn hơn key, đến một vị trí phía trước
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
// Hàm tìm kiếm tuyến tính
int linearSearch(int array[], int totalElement, int elementSearch) {
    for (int i = 0; i < totalElement; i++) {
        if (array[i] == elementSearch) {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Nếu không tìm thấy, trả về -1
}
// Hàm tìm kiếm nhị phân
int binarySearch(int array[], int totalElement, int elementSearch) {
    int left = 0;
    int right = totalElement - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiểm tra nếu phần tử ở giữa là phần tử cần tìm
        if (array[mid] == elementSearch) {
            return mid; // Trả về vị trí tìm thấy
        }

        // Nếu phần tử ở giữa nhỏ hơn phần tử cần tìm, tìm trong nửa bên phải
        if (array[mid] < elementSearch) {
            left = mid + 1;
        } else { // Nếu lớn hơn, tìm trong nửa bên trái
            right = mid - 1;
        }
    }
    return -1; // Nếu không tìm thấy, trả về -1
}
// Hàm in ra kết quả tìm kiếm
void printSearchResult(int index, int elementSearch) {
    if (index != -1) {
        printf("Phan tu %d duoc tim thay tai chi so: %d\n", elementSearch, index);
    } else {
        printf("Phan tu %d khong duoc tim thay trong mang.\n", elementSearch);
    }
}
// Hàm chính
int main() {
    int totalElement = inputSize();
    int array[MAX_LENGTH];

    inputArray(array, totalElement);

    // Sắp xếp mảng
    insertionSort(array, totalElement);
    printf("Mang sau khi sap xep:\n");
    printArray(array, totalElement);

    // Nhập phần tử cần tìm kiếm
    int elementSearch;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &elementSearch);

    // Tìm kiếm tuyến tính
    int linearIndex = linearSearch(array, totalElement, elementSearch);
    printSearchResult(linearIndex, elementSearch);

    // Tìm kiếm nhị phân
    int binaryIndex = binarySearch(array, totalElement, elementSearch);
    printSearchResult(binaryIndex, elementSearch);

    return 0;
}
// Phân tích độ phức tạp thời gian:
// - Thuật toán sắp xếp chèn có độ phức tạp thời gian trung bình và xấu nhất là O(n^2).
// - Tìm kiếm tuyến tính có độ phức tạp thời gian O(n).
// - Tìm kiếm nhị phân có độ phức tạp thời gian O(log n) .