# Tháp Hà Nội — tuần 2

## Bài toán và dữ liệu

Có ba cột A, B, C. Ban đầu `n` đĩa nằm trên cột A, đĩa lớn ở dưới, đĩa nhỏ ở trên.
Chuyển toàn bộ đĩa từ A sang C, dùng B làm cột phụ. Mỗi bước chỉ được chuyển
một đĩa ở trên cùng và không được đặt đĩa lớn lên đĩa nhỏ.

- **Input:** một số nguyên `n`, `0 <= n <= 20`. Đĩa 1 nhỏ nhất, đĩa `n` lớn nhất.
- **Output:** mỗi dòng có dạng `Dia k: X -> Y`, cuối cùng là `Tong so buoc: s`.
- `n = 0` nghĩa là không có đĩa, không cần bước di chuyển nào.
- Input sai được báo bằng `So dia phai la so nguyen tu 0 den 20.` và mã thoát 1.

Chương trình không in lời nhắc nhập để dễ kiểm tra input/output. Giới hạn 20
tránh in quá nhiều dòng: riêng 20 đĩa đã cần 1.048.575 bước. Khi chạy tương tác,
nhập số rồi kết thúc input (Windows: Ctrl+Z rồi Enter; Linux/macOS: Ctrl+D),
hoặc truyền input bằng các lệnh dưới đây.

## 1. Thủ tục đệ quy — `de_quy.cpp`

Thủ tục `thapHaNoi(soDia, cotNguon, cotDich, cotPhu)` giải bài toán con với
`soDia` đĩa:

1. Nếu không có đĩa, kết thúc thủ tục.
2. Chuyển `soDia - 1` đĩa phía trên từ cột nguồn sang cột phụ, dùng cột đích làm phụ.
3. Chuyển đĩa `soDia` từ cột nguồn sang cột đích.
4. Chuyển `soDia - 1` đĩa từ cột phụ sang cột đích, dùng cột nguồn làm phụ.

Ví dụ 2 đĩa: chuyển đĩa 1 từ A sang B, chuyển đĩa 2 từ A sang C, rồi chuyển
đĩa 1 từ B sang C. Các lời gọi nhỏ hơn được thực hiện nhờ ngăn xếp lời gọi của C++.

## 2. Khử đệ quy — `khu_de_quy.cpp`

Thay ngăn xếp lời gọi bằng `stack<CongViec>`. Mỗi công việc lưu số đĩa,
ba cột và cờ `chiChuyen`:

- `false`: cần giải cả bài toán con.
- `true`: chỉ chuyển một đĩa có số hiệu `soDia`, không tách thành bài toán nhỏ nữa.

Các bước:

1. Đưa công việc chuyển `n` đĩa từ A sang C vào ngăn xếp.
2. Khi ngăn xếp còn phần tử, lấy công việc trên cùng ra.
3. Nếu số đĩa bằng 0, bỏ qua. Nếu chỉ có 1 đĩa hoặc `chiChuyen = true`, in bước di chuyển.
4. Với bài toán nhiều đĩa, đẩy ba công việc theo **thứ tự ngược**:
   chuyển `n - 1` đĩa từ phụ sang đích; chuyển đĩa `n` từ nguồn sang đích;
   chuyển `n - 1` đĩa từ nguồn sang phụ.
5. Lặp lại đến khi ngăn xếp rỗng.

Ngăn xếp hoạt động theo LIFO: vào sau, ra trước. Vì vậy công việc chuyển
`n - 1` đĩa từ nguồn sang phụ sẽ được xử lý trước, đúng như bản đệ quy.
Thủ tục này dùng vòng lặp, không gọi lại chính nó.

## Độ đúng và độ phức tạp

Đĩa lớn nhất chỉ được chuyển khi các đĩa nhỏ đã sang cột phụ. Hai bài toán
con cũng tuân thủ quy tắc này, nên không có bước đặt đĩa lớn lên đĩa nhỏ.
Với `T(0) = 0`, số bước là `T(n) = 2 * T(n - 1) + 1 = 2^n - 1`.
Đây cũng là số bước tối thiểu: trước và sau khi chuyển đĩa lớn nhất đều phải
chuyển toàn bộ `n - 1` đĩa nhỏ.

Cả hai cách tốn thời gian `O(2^n)` và bộ nhớ phụ `O(n)`. Bản khử đệ quy
vẫn cần ngăn xếp tường minh; khử đệ quy không làm giảm số bước phải in.

## Biên dịch và chạy

Dùng trình biên dịch hỗ trợ C++17. Trong PowerShell, từ thư mục gốc repository:

```powershell
cd "BT tren lop/thap_ha_noi_tuan_2"
g++ -std=c++17 -Wall -Wextra -pedantic de_quy.cpp -o de_quy.exe
g++ -std=c++17 -Wall -Wextra -pedantic khu_de_quy.cpp -o khu_de_quy.exe
"3" | .\de_quy.exe
"3" | .\khu_de_quy.exe
```

Trên Linux/macOS, biên dịch tương tự và chạy bằng `echo 3 | ./de_quy.exe`.
Hai file `.cpp` là hai chương trình độc lập, không biên dịch chung vào một chương trình.

## Test cases

Các output dưới đây áp dụng cho cả hai cách.

### Không có đĩa

Input:

```text
0
```

Output:

```text
Tong so buoc: 0
```

### Một đĩa

Input:

```text
1
```

Output:

```text
Dia 1: A -> C
Tong so buoc: 1
```

### Hai đĩa

Input:

```text
2
```

Output:

```text
Dia 1: A -> B
Dia 2: A -> C
Dia 1: B -> C
Tong so buoc: 3
```

### Ba đĩa

Input:

```text
3
```

Output:

```text
Dia 1: A -> C
Dia 2: A -> B
Dia 1: C -> B
Dia 3: A -> C
Dia 1: B -> A
Dia 2: B -> C
Dia 1: A -> C
Tong so buoc: 7
```

### Input không hợp lệ

Mỗi input trong bảng là một lần chạy riêng:

| Input | Output | Mã thoát |
| --- | --- | --- |
| `-1` | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| `21` | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| `abc` | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| `2.5` | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| `3 4` | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| Input rỗng | `So dia phai la so nguyen tu 0 den 20.` | 1 |
| `999999999999` | `So dia phai la so nguyen tu 0 den 20.` | 1 |

### Kiểm thử tự động

Cần Python 3 và `g++` trên PATH. Chạy trong thư mục bài tập:

```powershell
python test_thap_ha_noi.py
```

Output khi tất cả kiểm tra đạt:

```text
PASS: 42 lan chay; buoc di hop le, so buoc toi thieu, hai cach cho cung ket qua.
```

Script tự biên dịch vào thư mục tạm rồi kiểm tra:

- `n = 0..12`: mô phỏng ba cột, kiểm tra đĩa di chuyển ở trên cùng, không đặt
  đĩa lớn lên đĩa nhỏ, cuối cùng toàn bộ đĩa nằm ở C và có đúng `2^n - 1` bước.
- So sánh toàn bộ output của hai cách cho `n = 0..12`, đối chiếu mẫu 2 đĩa.
- `n = 20`: kiểm tra số dòng và dòng tổng kết, không lưu toàn bộ output vào bộ nhớ.
- Bảy trường hợp input sai trong bảng trên cho từng chương trình.

## Nộp bài

Kết quả kiểm tra mã nguồn bằng Copydetect và giới hạn của phép đối chiếu:
[KIEM_TRA_TUONG_DONG.md](KIEM_TRA_TUONG_DONG.md).

Nộp [link repository Study](https://github.com/minion2007vu-bit/Study)
hoặc [link thư mục bài tuần 2](https://github.com/minion2007vu-bit/Study/tree/master/BT%20tren%20lop/thap_ha_noi_tuan_2).
Không nộp file nguồn riêng hay file thực thi.
