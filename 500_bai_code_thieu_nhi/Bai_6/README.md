# Đề bài: Find the largest subarray formed by consecutive integers
**Given an integer array, find the largest subarray formed by consecutive integers. The subarray should contain all distinct values.**

## Mô tả giải thuật:
1. Sử dụng unordered map như cuốn từ điển, duyệt vòng lặp qua các phần tử trong mảng.
2. Nếu phần tử đó chưa có trong map thì sẽ thêm vào.
3. Nếu tìm được "key" của 1 phần tử tức đã tồn tại trong map thì dừng vòng lặp và lưu lại số phần tử của mảng con hiện tại.
4. Lặp lại n lần rồi chốt max_length của mảng con.
5. In ra mảng con đó sử dụng start và index j là phần tử cuối cùng của mảng.


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. In ra mảng dài nhất.

## Test case:
**Test case 1:**  
Input:  
8  
2 0 1 3 5 4 0 6  
Output:  
The largest subarray is {2, 0, 1, 3, 5, 4}  

**Test case 2:**  
Input:  
10  
1 2 3 4 5 8 6 7 2 9  
Output:  
The largest subarray is {1, 2, 3, 4, 5, 8, 6, 7}    