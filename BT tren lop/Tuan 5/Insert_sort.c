#include<stdio.h>

//Insert sort

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && A[j] < A[j-1]){
            swap(&A[j], &A[j-1]);
            j = j-1;
        }
        for(int k = 0; k < n; k++){
            printf("%d ", A[k]);
        }
        printf("\n");
    }
    return 0;
}