#include<stdio.h>
#include<stdbool.h>

void Find_subarray_0(int *arr, int size){
    int sum;
    bool found = false;
    for (int i = 0; i < size; i++){
        sum = 0;
        for(int j = i; j < size; j++){
            sum += arr[j];
            if(sum == 0){
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
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Find_subarray_0(arr, n);
}