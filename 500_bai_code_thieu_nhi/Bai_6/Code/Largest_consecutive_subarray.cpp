#include<stdio.h>
#include<iostream>
#include<unordered_map>
using namespace std;

void Largest_subarr(int *arr, int size) {
    int start = 0;
    int max_length = 0;

    for (int i = 0; i < size; i++) {
        unordered_map<int, int> list;
        int j;
        for (j = i; j < size; j++) {
            if (list.find(arr[j]) != list.end()) {
                break;
            }
            list[arr[j]] = j;
        }
        int length = j - i;
        if (length > max_length) {
            max_length = length;
            start = i;
        }
    }
    cout << "The largest subarray is {";
    for (int i = start; i < start + max_length; i++) {
        if (i > start) {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "}\n";
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Largest_subarr(arr, n);
}