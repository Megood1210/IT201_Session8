#include <stdio.h>
#define MAX_LENGTH 1000

// Hàm hoán đổi 2 phần tử
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm chia mảng và trả về chỉ số pivot sau cùng
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Hàm sắp xếp mảng theo giải thuật Quick Sort
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        // Sắp xếp 2 nửa mảng
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr,0, n-1);
    //In kết quả ra màn hình
    printArray(arr, n);

    return 0;
}
// Độ phức tạp thời gian của thuật toán
//  - Tốt nhất: O(n log n) nếu mảng đã được chia thành 2 phần bằng nhau
//  - Trung bình: O(n log n) - Nếu như mảng chia thành 2 phần gần bằng nhau
//  - Tệ nhất: O(n^2) - Trong trường hợp mảng được sắp xếp giảm dần


