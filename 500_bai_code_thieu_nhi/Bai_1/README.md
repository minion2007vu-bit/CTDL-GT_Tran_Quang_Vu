# Đề bài: Find a pair with the given sum in an array
**Given an unsorted integer array, find a pair with the given sum in it.**

## Mô tả giải thuật:
1. Hàm find_Pair_sum với đầu vào là con trỏ chỉ vào mảng, tổng muốn tìm, kích thước mảng.
2. Tạo unordered_map rỗng với 0 phần tử. Và 1 biến boolean để biết có tìm được cặp nào không, biến này khởi tạo = false.
3. Mỗi vòng lặp (theo kích thước mảng) sẽ tìm phần bù của nó để tạo thành tổng muốn tìm.
4. Sau đó mới thêm phần tử vào mảng (để tránh trường hợp số đó tự tạo thành với chính nó thành tổng muốn tìm).
5. Nếu tìm được thì biến boolean = true và in ra cặp tìm được.
6. Nếu duyệt hết kích thước mảng mà không có cặp nào thì in ra "No pair found".

## Dữ liệu Input & Output:
### Input:
1. Nhập vào n: kich thước mảng.
2. Nhập vào sum: tổng muốn tìm.
3. Vòng lặp for để điền các phần tử vào mảng.

### Output:
1. Nếu tìm được: "Pair found (a, b)" với a: phần tử đang duyệt, b: phần bù tạo thành tổng.
2. Nếu không tìm được: in ra "No pair found".

## Test case:
**Test case 1:**\
Input:\
5\
10\
3 6 5 4 7\
Output:\
Pair found (3, 7)\
Pair found (6, 4)

**Test case 2:**\
Input:\
7\
9\
3 7 5 0 8 5 7\
Output:\
No pair found