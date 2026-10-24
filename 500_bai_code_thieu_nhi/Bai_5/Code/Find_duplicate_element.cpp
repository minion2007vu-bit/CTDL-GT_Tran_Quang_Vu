#include<stdio.h>
#include<unordered_map>
#include<iostream>
using namespace std;

void Find_dup(int *arr, int size){
    unordered_map<int, int> list;
    bool found = false;
    for (int i = 0; i < size; i++){
        if(list.find(arr[i]) != list.end()){
            cout << "Duplicate element found: " << arr[i] << endl;
            found = true;
        }
        list[arr[i]] = i;
    }
    if(!found) cout << "No duplicate element found" << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Find_dup(arr, n);
}
