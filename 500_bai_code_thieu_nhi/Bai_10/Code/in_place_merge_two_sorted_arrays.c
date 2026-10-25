#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_sorted(int *arr, int size){
    printf("{");
    for(int i = 0; i < size; i++){
        if(i == size - 1){
            printf("%d}\n", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
}

void Sort_mix_arrays(int *x, int *y, int m, int n){
    if(n > 0){
        for(int i = 0; i < m; i++){
            if(x[i] > y[0]){
                swap(&x[i], &y[0]);
                int value = y[0];
                int j = 1;
                while(j < n && y[j] < value){
                    y[j - 1] = y[j];
                    j++;
                }
                y[j - 1] = value;
            }
        }
    }
    printf("X[] = ");
    print_sorted(x, m);
    printf("Y[] = ");
    print_sorted(y, n);
}

int main(){
    int m, n;
    scanf("%d", &m);
    int x[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
    }
    scanf("%d", &n);
    int y[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &y[i]);
    }
    Sort_mix_arrays(x, y, m, n);
}