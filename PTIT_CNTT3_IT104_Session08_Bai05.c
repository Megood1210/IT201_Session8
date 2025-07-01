#include <stdio.h>
#define MAX_LENGTH 1000

// Hàm sắp xếp theo thuật toán sắp xếp chèn
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm in mảng
void printArray(int arr[], int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        if (i < n - 1){
            printf(",");
        }
    }
    printf("]");
}
int main(){
    int n, arr[MAX_LENGTH];
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    // Kiểm tra số phần tử
    if (n < 0 || n > MAX_LENGTH){
        printf("So luong phan tu khong hop le");
        return 0;
    }
    // Nhập các phần tử của mảng
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Gọi hàm sắp xếp nổi bọt
    insertionSort(arr, n);
    //In kết quả ra màn hình
    printArray(arr, n);

    return 0;
}
// Độ phức tạp thời gian của thuật toán
//  - Tốt nhất: O(n) nếu mảng đã được sắp xếp
//  - Trung bình: O(n^2) - Nếu như mảng chưa được sắp xếp hoặc mảng bất kỳ
//  - Tệ nhất: O(n^2) - Trong trường hợp mảng được sắp xếp giảm dần

