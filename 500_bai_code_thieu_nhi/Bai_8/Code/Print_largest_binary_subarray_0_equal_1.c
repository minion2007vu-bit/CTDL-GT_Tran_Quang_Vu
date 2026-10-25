#include<stdio.h>

void Print_longest_binary(int *arr, int start, int m){
    printf("The longest subarray is: {");
    for(int i = start; i < start + m; i++){
        if(i == start + m - 1){
            printf("%d}\n", arr[i]);
            break;
        }
        printf("%d ", arr[i]);
    }
}

void Find_binary_0_1_equal(int *arr, int size){
    int sub_size, max_length = -1, zeros_count, ones_count;
    int index[size];
        for(int i = 0; i < size; i++){
        index[i] = 0;
    }
    for(int i = 0; i < size; i++){
        zeros_count = 0;
        ones_count = 0;
        sub_size = 0;
        for(int j = i; j < size; j++){
            if(arr[j] == 0) zeros_count++;
            else ones_count++;
            sub_size++;
            if(zeros_count == ones_count && sub_size >= max_length){
                max_length = sub_size;
                index[i] = sub_size;
            }
        }
    }
    for(int i = 0; i < size; i++){
            if(index[i] == max_length){
                Print_longest_binary(arr, i, index[i]);
            }
        }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Find_binary_0_1_equal(arr, n);
}