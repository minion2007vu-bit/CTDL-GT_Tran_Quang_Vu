#include<stdio.h>

void In_mang(int *arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Merge_array(int *arr, int m, int n, int p, int size){
	int i = m, j= n + 1;
	while (i < j && j <= p){
		if (arr[i] <= arr[j]) i++;
		else{
			int temp = arr[j];
			for (int k = j-1; k >= i; k--){
				arr[k+1] = arr[k];
            }
			arr[i] = temp;
			i++;
            j++;
            In_mang(arr, size);
		}
	}
}

void Split_Merge(int *arr, int dau, int cuoi, int size){
	if (dau >= cuoi) return;
	int m = (dau + cuoi) / 2;
	Split_Merge(arr, dau, m, size);
	Split_Merge(arr, m+1, cuoi, size);
	Merge_array(arr, dau, m, cuoi, size);
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
    Split_Merge(arr, 0, n - 1, n);
    printf("Mang sau khi sap xep: ");
    In_mang(arr, n);
    return 0;
}