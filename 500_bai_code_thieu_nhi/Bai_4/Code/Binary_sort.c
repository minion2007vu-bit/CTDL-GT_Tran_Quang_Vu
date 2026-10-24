#include<stdio.h>

void Sort_binary(int *arr, int size){
    int count_ones = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 1) count_ones++;
    }
    int count_zeros = size - count_ones;
    for(int i = 0; i < size; i++){
        if(i < count_zeros) arr[i] = 0;
        else arr[i] = 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Sort_binary(arr, n);
    printf("{");
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d}", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
}