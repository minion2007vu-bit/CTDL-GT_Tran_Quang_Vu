#include<stdio.h>

//Selection Sort

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        int index = i;
        for(int j = i + 1; j < n; j++) {
            if (A[j] < A[index]) {
                index = j;
            }
        }
        int temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}