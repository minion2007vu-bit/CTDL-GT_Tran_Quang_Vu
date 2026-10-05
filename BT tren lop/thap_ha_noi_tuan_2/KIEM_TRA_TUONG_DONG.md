# Kết quả kiểm tra tương đồng mã nguồn

Ngày kiểm tra: **05/10/2026**. Công cụ: [Copydetect](https://github.com/blingenf/copydetect)
**0.5.0**, dùng bộ phân tích C++ của Pygments **2.21.0**. Công cụ chạy trên máy,
không tải mã nguồn bài tập lên dịch vụ kiểm tra bên ngoài.

## Phạm vi và kết quả

Kiểm tra toàn bộ `de_quy.cpp` và `khu_de_quy.cpp` với ba file Tháp Hà Nội C++
công khai dưới đây. Hai bản của bài tập không được dùng làm mẫu đối chiếu của
nhau vì cùng thực hiện một bài toán và cùng định dạng input/output.

| File bài tập | Mẫu ygabo | Mẫu gmarella | Mẫu harry1357931 | Cao nhất |
| --- | ---: | ---: | ---: | ---: |
| `de_quy.cpp` | 0,00% | 0,00% | 21,62% | **21,62%** |
| `khu_de_quy.cpp` | 0,00% | 0,00% | 0,00% | **0,00%** |

Các tỷ lệ lấy phía **file bài tập** từ kết quả của công cụ, không lấy tỷ lệ
của file mẫu. Dữ liệu chưa làm tròn nằm trong [ket_qua_tuong_dong.json](ket_qua_tuong_dong.json).

**Không đạt yêu cầu cả hai bản có mức tương đồng dưới 2% trong lần kiểm tra này.**
Không có cơ sở để khẳng định tỷ lệ dưới 2% trên toàn Internet hay trên tập bài
của lớp. Tháp Hà Nội có cấu trúc đệ quy chuẩn rất ngắn; trùng cấu trúc thuật toán
không tự nó chứng minh sao chép. Code bài tập được viết trước khi tải các mẫu
đối chiếu, và không được sửa để làm giảm điểm của công cụ.

## Mẫu đối chiếu

1. [ygabo — hanoi.cpp](https://gist.github.com/ygabo/5898011): bản đệ quy dùng các stack biểu diễn cột.
2. [gmarella — tower_of_hanoi.cpp](https://gist.github.com/gmarella/9c3f2e243478f70923fbd076173d09aa): bản đệ quy có hiển thị trạng thái các cột.
3. [harry1357931 — TowersOfHanoi.cpp](https://github.com/harry1357931/Towers-of-Hanoi-Vector-cpp/blob/master/TowersOfHanoi.cpp): bản đệ quy in bước di chuyển.

Ba mẫu là một tập đối chiếu nhỏ, không đại diện cho tất cả cách viết bài này.
Không sao chép các file mẫu vào repository nộp bài. Hash SHA-256 của đúng các
file đã đối chiếu được lưu trong JSON để nhận biết nếu nguồn công khai thay đổi.

## Thiết lập kiểm tra

- Ngôn ngữ ép buộc: `cpp`.
- `noise_threshold = 25`, `guarantee_threshold = 25`; cửa sổ winnowing = 1.
- Có lọc/token hóa mã nguồn, không tắt chuẩn hóa tên biến và chuỗi.
- Không loại trừ boilerplate, không bỏ qua phần nào của hai file bài tập.
- Ngưỡng hiển thị báo cáo = 0, không giấu cặp có điểm tương đồng thấp.

Theo [tài liệu Copydetect](https://copydetect.readthedocs.io/en/latest/api.html),
ngưỡng này được tính trên ký tự sau khi lọc mã, không phải số dòng code.
Mức 0% nghĩa là không phát hiện đoạn trùng ở thiết lập đang dùng,
không phải giấy chứng nhận không đạo code.

## Chạy lại

Cài Copydetect vào môi trường Python kiểm tra riêng:

```powershell
python -m venv .venv-check
.\.venv-check\Scripts\python.exe -m pip install copydetect==0.5.0 pygments==2.21.0
```

Tải đúng ba file mẫu vào thư mục `mau_doi_chieu`. Sau đó chạy từ thư mục gốc
repository (không đưa thư mục mẫu vào commit):

```powershell
.\.venv-check\Scripts\python.exe -m copydetect -t "BT tren lop/thap_ha_noi_tuan_2" -r mau_doi_chieu -e cpp -n 25 -g 25 -d 0 -o cpp -a
```

Xem báo cáo HTML được sinh ra; đối chiếu hash và phiên bản thư viện trước khi
so sánh với kết quả đã lưu. Những lần chạy với mẫu khác hoặc thiết lập khác
có thể cho tỷ lệ khác.
