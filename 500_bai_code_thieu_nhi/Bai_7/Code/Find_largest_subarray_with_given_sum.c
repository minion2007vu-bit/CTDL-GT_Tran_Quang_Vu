#include<stdio.h>
#include<stdbool.h>

void Print_largest(int *arr, int start, int m){
    printf("The longest subarray is: {");
    for(int i = start; i < start + m; i++){
        if(i == start + m - 1){
            printf("%d} having length %d", arr[i], m);
            break;
        }
        printf("%d ", arr[i]);
    }
}

void Find_subarray_sum(int *arr, int x, int size){
    int sub_size, index = -1, sum, max_length = -1;
    bool found = false;
    for (int i = 0; i < size; i++){
        sum = 0;
        for(int j = i; j < size; j++){
            sum += arr[j];
            if(sum == x){
                sub_size = j - i + 1;
                if(sub_size > max_length){
                    max_length = sub_size;
                    index = i;
                }
                printf("Subarray found: {");
                for(int k = i; k < j; k++){
                    printf("%d, ", arr[k]);
                }
                printf("%d}\n", arr[j]);
                found = true;
            }
        }
    }
    if(!found) printf("No subarray found");
    else Print_largest(arr, index, max_length);
}

int main(){
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Find_subarray_sum(arr, x, n);
}