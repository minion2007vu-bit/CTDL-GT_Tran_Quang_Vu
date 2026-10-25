# Đề bài: Sort an array of 0’s, 1’s, and 2’s (Dutch National Flag Problem)
**Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.**

## Mô tả giải thuật:
1. Tạo biến đếm số 0 và 1.
2. Duyệt qua các phần tử của mảng input và thêm vào số đếm.
3. Sắp xếp các phần tử trong mảng dựa theo số đếm. Các phần tử có chỉ số < count_0 trở thành 0. Các phần tử có chỉ số < count_0 + count_1 trở thành số 1. Các phần tử còn lại phía sau của mảng trở thành số 2.

## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. In ra các mảng đã sắp xếp đúng thứ tự

## Test case:
**Test case 1:**  
Input:  
12  
0 1 2 2 1 0 0 2 0 1 1 0  
Output:  
{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2}     

**Test case 2:**  
Input:  
6  
0 1 2 0 2 1  
Output:  
{0, 0, 1, 1, 2, 2}  