#include<stdio.h>

//Selection Sort

int main(){
    int min, index, n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        min = A[i];
        for(int j = i; j < n; j++){
            index = i;
            if (A[i] > A[j]){
                min = A[j];
                index = j;
            }
        }
        int temp = A[i];
        A[i] = min;
        A[index] = temp;
    }
    return 0;
}