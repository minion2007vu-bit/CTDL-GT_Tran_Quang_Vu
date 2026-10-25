# Đề bài: In-place merge two sorted arrays
**Given two sorted arrays, X[] and Y[] of size m and n each, merge elements of X[] with elements of array Y[] by maintaining the sorted order, i.e., fill X[] with the first m smallest elements and fill Y[] with remaining elements. Do the conversion in-place and without using any other data structure.**

## Mô tả giải thuật:
1. Tạo và điền các phần tử vào 2 mảng X và Y theo đúng thứ tự tăng dần ở mỗi mảng.
2. So sánh lần lượt từng phần tử của mảng X với phần tử đầu của Y. Nếu nhỏ hơn thì đổi chỗ.
3. Lấy giá trị trung gian value lưu lại phần tử vừa chuyển sang Y.
4. Dùng vòng lặp while để so sánh phần tử vừa chuyển với phần tử liền kề (j), nếu lớn hơn thì lấy giá trị đó và tịnh tiến trị số j sang phần tử tiếp theo để so sánh.
5. Lặp lại cho đến khi không còn thoả mãn nữa và phần tử dừng lại j-1 sẽ lấy giá trị value.


## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng X.
2. Vòng lặp for để điền các phần tử vào mảng X.
3. Nhập vào m: kích thước mảng Y.
4. Vòng lặp for để điền các phần tử vào mảng Y.

### Output:
1. In ra mảng X đã sắp xếp.
2. In ra mảng Y đã sắp xếp.

## Test case:
**Test case 1:**  
Input:  
5  
1 4 7 8 10  
3  
2 3 9  
Output:  
X[] = {1, 2, 3, 4, 7}  
Y[] = {8, 9, 10}  

**Test case 2:**  
Input:  
7  
1 3 4 8 9 10 14  
5  
4 5 6 13 18  
Output:  
X[] = {1, 3, 4, 4, 5, 6, 8}  
Y[] = {9, 10, 13, 14, 18}  