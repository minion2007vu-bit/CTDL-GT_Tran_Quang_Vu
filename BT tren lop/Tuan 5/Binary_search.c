#include<stdio.h>
#include<math.h>

int Binary_search(int *arr, int size, int x){
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right){
        mid = (left + right)/2;
        if (x == arr[mid]) return mid;
        if (x < arr[mid]) right = mid - 1;
        else left = mid + 1; 
    }
}

int main(){
    int n, x;
    printf("Nhap so phan tu cua mang:");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Nhap so can tim trong mang:");
    scanf("%d", &x);
    printf("So can tim o vi tri thu %d trong mang", Binary_search(arr, n, x) + 1);
    return 0;
}