#include<stdio.h>
#include<unordered_map>
#include<iostream>
using namespace std;

void find_Pair_sum (int *arr, int sum, int size){
    bool pair_found = false;
    unordered_map<int, int> list;
    for (int i = 0; i < size-1; i++){
        list[arr[i]] = i;
        if(list.find(sum - arr[i]) != list.end()){
            cout << "Pair found " << "(" << arr[i] << ", " << sum - arr[i] << ")" << endl;
            pair_found = true;
        }
    }
    if (!pair_found){
        cout << "No pair found" << endl;
    }
}

int main(){
    int n, sum;
    cin >> n;
    cin >> sum;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    find_Pair_sum(arr, sum, n);
}

