#include<stdio.h>

//Insert sort

void swap(int a, int b){
    int temp = b;
    b = a;
    a = temp;
}

int main(){
    int n;
    int A[n];
    for(int i = 1; i < n; i++){
        int j = i;
        while(A[j] < A[j-1]){
            swap(A[j], A[j-1]);
            j = j-1;
            if(j == 1) break;
        }
    }
}