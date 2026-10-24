# Đề bài: Find the duplicate element in a limited range array
**Given a limited range array of size n containing elements between 1 and n-1 with one element repeating, find the duplicate number in it without using any extra space.**

## Mô tả giải thuật:
1. Sử dụng unordered map như cuốn từ điển, duyệt vòng lặp qua các phần tử trong mảng.
2. Nếu phần tử đó chưa có trong map thì sẽ thêm vào.
3. Nếu tìm được "key" của 1 phần tử tức đã tồn tại trong map thì in ra phần tử trùng đó.
4. Nếu duyệt hết các phần tử mà không thấy trùng thì biến boolean = false sẽ cho in ra "No duplicate element found".


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. Nếu tìm được: "Duplicate element found: ".  
2. Nếu không tìm được: in ra "No duplicate element found".

## Test case:
**Test case 1:**  
Input:  
7  
1 1 2 3 6 3 7  
Output:  
Duplicate element found: 1  
Duplicate element found: 3  

**Test case 2:**  
Input:  
5  
1 2 3 4 5    
Output:  
No duplicate element found  