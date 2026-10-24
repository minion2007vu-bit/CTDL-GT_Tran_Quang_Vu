# Đề bài: Sort binary array in linear time
**Given a binary array, sort it in linear time and constant space. The output should print all zeros, followed by all ones.**

## Mô tả giải thuật:
1. Vòng lặp đầu tiên quét qua mảng để đếm số phần tử 1.
2. Tính được số phần tử 0 từ hiệu của tổng số phần tử với số phần tử 1.
3. Gán giá trị 0 với i phần tử đầu tiên bằng việc so sánh index với số phần tử 0.
4. Những phần tử còn lại gán là 1.
5. In ra mảng mới

## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. Mảng mới đã được sắp xếp lại.

## Test case:
**Test case 1:**  
Input:  
10  
1 1 0 1 0 1 1 0 0 1   
Output:  
{0, 0, 0, 0, 1, 1, 1, 1, 1, 1}   

**Test case 2:**  
Input:  
5  
1 0 0 1 1    
Output:  
{0, 0, 1, 1, 1}  
