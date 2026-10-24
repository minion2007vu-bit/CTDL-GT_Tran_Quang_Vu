# Đề bài: Check if a subarray with 0 sum exists or not
**Given an integer array, check if it contains a subarray having zero-sum.**

## Mô tả giải thuật:
1. Hàm Find_subarray_0 có đầu vào là con trỏ của mảng và kích thước mảng.
2. Sử dụng 2 vòng lặp for để tìm mảng con có tổng bằng 0.
3. Vòng lặp thứ nhất để xét từng phần tử i trong mảng với vai trò là phần tử đầu của mảng con.
4. Vòng lặp thứ hai bên trong vòng lặp thứ nhất để tính tổng từ phần thứ nhất i cộng với lần lượt từng phần tử sau. Dừng lại khi tổng bằng 0 hoặc duyệt hết mảng.
5. Nếu tổng bằng 0 thì dùng một vòng lặp nữa để in các phần tử của mảng con từ i đến phần tử dừng lại j.
6. Biến boolean để nhận biết có tìm được mảng con nào hay không, nếu không in ra "No subarray found".


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. Nếu tìm được: "Subarray found: {}".
2. Nếu không tìm được: in ra "No subarray found".

## Test case:
**Test case 1:**  
Input:  
10  
3 4 -7 3 1 3 1 -4 -2 -2  
Output:  
Subarray found: {3, 4, -7}  
Subarray found: {3, 4, -7, 3, 1, 3, 1, -4, -2, -2}  
Subarray found: {4, -7, 3}  
Subarray found: {-7, 3, 1, 3}  
Subarray found: {3, 1, 3, 1, -4, -2, -2}  
Subarray found: {3, 1, -4}  

**Test case 2:**  
Input:  
12  
3 -9 7 5 -4 6 6 -9 -2 -3 5 1  
Output:  
Subarray found: {3, -9, 7, 5, -4, 6, 6, -9, -2, -3}  
Subarray found: {-9, 7, 5, -4, 6, 6, -9, -2}  
Subarray found: {-4, 6, 6, -9, -2, -3, 5, 1}  
Subarray found: {-2, -3, 5}  
