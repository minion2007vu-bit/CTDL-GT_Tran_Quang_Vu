# Đề bài: Find maximum length subarray having a given sum
**Given an integer array, find the maximum length subarray having a given sum.**

## Mô tả giải thuật:
1. Hàm Find_subarray_SUM có đầu vào là con trỏ của mảng, tổng muốn lấy x và kích thước mảng.
2. Sử dụng 2 vòng lặp for để tìm mảng con có tổng bằng x. Sử dụng thêm biến index và max_length để lưu lại kỉ lục.
3. Vòng lặp thứ nhất để xét từng phần tử i trong mảng với vai trò là phần tử đầu của mảng con.
4. Vòng lặp thứ hai bên trong vòng lặp thứ nhất để tính tổng từ phần thứ nhất i cộng với lần lượt từng phần tử sau. Dừng lại khi tổng bằng x hoặc duyệt hết mảng.
5. Nếu tổng bằng x thì dùng một vòng lặp nữa để in các phần tử của mảng con từ i đến phần tử dừng lại j.
6. Biến boolean để nhận biết có tìm được mảng con nào hay không, nếu không in ra "No subarray found".
7. Gọi hàm in Print_largest với đầu vào là con trỏ mảng, index, max_length để in ra mảng con dài nhất.


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Nhập vào x: tổng muốn tìm.  
3. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. Nếu tìm được: "Subarray found: {}".
2. In ra mảng con dài nhất.
3. Nếu không tìm được: in ra "No subarray found".

## Test case:
**Test case 1:**  
Input:  
9  
8  
5 6 -5 5 3 5 3 -2 0  
Output:  
Subarray found: {-5, 5, 3, 5}  
Subarray found: {5, 3}  
Subarray found: {3, 5}  
Subarray found: {5, 3}  
The longest subarray is: {-5 5 3 5} having length 4  

**Test case 2:**  
Input:  
12
6  
3 -9 7 5 -4 6 6 -9 -2 -3 5 1  
Output:  
Subarray found: {3, -9, 7, 5}  
Subarray found: {3, -9, 7, 5, -4, 6, 6, -9, -2, -3, 5, 1}  
Subarray found: {7, 5, -4, 6, 6, -9, -2, -3}  
Subarray found: {6}  
Subarray found: {6}  
Subarray found: {5, 1}  
The longest subarray is: {3 -9 7 5 -4 6 6 -9 -2 -3 5 1} having length 12  
