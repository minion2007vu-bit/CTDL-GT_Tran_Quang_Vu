#include<stdio.h>

void Sort_0_1_2(int *arr, int size){
    int count_1 = 0, count_0 = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0) count_0++;
        else if(arr[i] == 1) count_1++;
    }
    for(int i = 0; i < size; i++){
        if(i < count_0) arr[i] = 0;
        else if(i < count_0 + count_1) arr[i] = 1;
        else arr[i] = 2;
    }
    printf("{");
    for(int i = 0; i < size; i++){
        if(i == size - 1){
            printf("%d}", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Sort_0_1_2(arr, n);
}