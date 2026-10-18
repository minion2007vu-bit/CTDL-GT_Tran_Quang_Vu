#include<stdio.h>

void In_mang(int *arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Chia_sxep(int *arr, int left, int right, int chot, int size){
    int i = left;
    int j = right;
    while (i <= j){
        while (i <= right && arr[i] < chot) i++;
        while (j >= left && arr[j] > chot) j--;
        if (i <= j){
            swap(&arr[i], &arr[j]);
            In_mang(arr, size);
            i++;
            j--;
        }
    }
    return i;
}

void Quick_sort(int *arr, int left, int right, int size){
    if (left >= right) return;
    int chot = arr[left + (right - left) / 2];
    int chia = Chia_sxep(arr, left, right, chot, size);
    Quick_sort(arr, left, chia - 1, size);
    Quick_sort(arr, chia, right, size);
}

int main(){
    int n;
    printf("Nhap so phan tu cua mang:");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Quick_sort(arr, 0, n - 1, n);
}