#include <stdio.h>
#define MAX_LENGTH 1000
// Hàm tìm kiếm phần tử theo thuật
int linearSearch(int arr[], int totalElement, int elementSearch){
    for (int i = 0; i < totalElement; i++){
        // Lấy phần tử để so sánh với elementSearch
        if (arr[i] == elementSearch){
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1;
}

int main(){
    int n, elementSearch;
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
    // Nhập phần tử cần tìm kiếm
    printf("searh = ");
    scanf("%d", &elementSearch);

    int result =  linearSearch(arr, n, elementSearch);
    // Kiểm thử thuật toán tìm kiếm tuyến tính và in kết quả ra màn hình
    if (result == -1){
        printf("Khong ton tai phan tu");
    }else{
        printf("vi tri thu %d",result);
    }
    return 0;
}
// Độ phức tạp thời gian của thuật toán
//  - Tốt nhất: O(1) nếu phần tử nằm ở đầu mảng
//  - Trung bình: O(n/2) - Nếu như phần tử nằm ở vị trí thứ 2, 3...
//  - Tệ nhất: O(n) - Trong trường hợp phần tử nằm ở gần hoặc cuối mảng

