# Đề bài: Find the largest subarray having an equal number of 0’s and 1’s
**Given a binary array containing 0’s and 1’s, find the largest subarray with equal numbers of 0’s and 1’s.**

## Mô tả giải thuật:
1. Tạo 1 mảng song song bằng kích thước của mảng input.
2. Các phần tử tương ứng với phần thứ tự phần tử đầu tiên đang xét sẽ lưu lại kỉ lục về độ dài.
3. Thuật toán quét và lưu lại max_length như những bài trước.
4. Index[i] với i là phần tử đầu tiên và giá trị là độ dài của mảng con.
5. Sau khi duyệt hết qua các mảng thì so sánh max_length cuối cùng với giá trị các index[i], nếu bằng nhau thì gọi hàm in.
6. Hàm in với đầu vào là (mảng input, vị trí phần tử đầu tiên, độ dài của mảng con).


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. In ra các mảng con có kích thước lớn nhất thoả mãn yêu cầu đề bài.

## Test case:
**Test case 1:**  
Input:  
7  
0 0 1 0 1 0 0  
Output:  
The longest subarray is: {0 1 0 1}  
The longest subarray is: {1 0 1 0}    

**Test case 2:**  
Input:  
12  
0 1 1 1 0 1 0 0 1 0 0 1  
Output:  
The longest subarray is: {0 1 1 1 0 1 0 0 1 0 0 1}  
