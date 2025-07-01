#include <stdio.h>
#define MAX_LENGTH 1000

// Hàm sắp xếp mảng tăng dần bằng sắp xếp chọn
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int n, int x){
    int left = 0;
    int right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == x){
            return mid; // Tìm thấy tại vị trí mid
        }else if (arr[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy
}
int main(){
    int n;
    // Nhập số lượng phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    // Kiểm tra số phần tử
    if (n < 0 || n > MAX_LENGTH){
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int arr[MAX_LENGTH];
    // Nhập các phần tử vào mảng
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Sắp xếp mảng trước khi tìm kiếm
    selectionSort(arr, n);
    // Nhập phần tử cần tìm kiếm
    int x;
    printf("search = ");
    scanf("%d", &x);
    // Gọi hàm tìm kiếm nhị phân
    int result =  binarySearch(arr, n, x);
    // Kiểm thử thuật toán tìm kiếm nhị phân và in kết quả ra màn hình
    if (result != -1){
        printf("vi tri thu %d",result + 1);
    }else{
        printf("Khong ton tai phan tu");
    }
    return 0;
}
// Độ phức tạp thời gian của thuật toán
//  - Tốt nhất: O(1) nếu phần tử nằm ở giữa mảng và mảng đã được sắp xếp
//  - Trung bình: O(n^2) - Nếu như mảng chưa được sắp xếp
//  - Tệ nhất: O(n^2) - Trong trường hợp phần tử nằm ở cuối mảng hoặc không tìm thấy phần tử và khi mảng được
//  sắp xếp giảm dần