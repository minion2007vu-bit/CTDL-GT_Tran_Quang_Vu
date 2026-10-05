# Bài tập Cấu trúc dữ liệu và Giải thuật

Repository `Study` dùng riêng để lưu bài tập môn CTDL & GT.

## Bài tập theo tuần

Đặt thư mục bài mới trong `BT tren lop` theo mẫu `ten_bai_tap_tuan_so`,
viết tên không dấu và dùng dấu gạch dưới giữa các từ.
Mỗi bài có code, `README.md` giải thích thuật toán và test case với input/output.

| Tuần | Bài tập | Nội dung |
| --- | --- | --- |
| 2 | [Tháp Hà Nội](BT%20tren%20lop/thap_ha_noi_tuan_2/README.md) | Đệ quy, khử đệ quy bằng stack, test tự động |

Các file bài cũ ở `BT tren lop` được giữ tại vị trí hiện có. Phần diễn giải
bài slide 26 trước đây được giữ ở cuối README này.

## Các lệnh Git cần dùng

Cài Git và cấu hình tên/email của chính bạn một lần:

```powershell
git config --global user.name "Ten cua ban"
git config --global user.email "email-cua-ban@example.com"
```

Lấy repository về máy trong lần đầu:

```powershell
git clone https://github.com/minion2007vu-bit/Study.git
cd Study
```

Mỗi lần làm bài, cập nhật trước khi sửa code:

```powershell
git pull --ff-only origin master
```

`pull` tải thay đổi trên GitHub về và cập nhật nhánh đang làm việc.
Nếu lệnh báo hai nhánh đã phân kỳ, cần xử lý khác biệt trước; không dùng force push.

Sau khi sửa, chạy test, xem thay đổi, tạo commit rồi đẩy lên GitHub:

```powershell
python "BT tren lop/thap_ha_noi_tuan_2/test_thap_ha_noi.py"
git status
git diff
git add "BT tren lop/thap_ha_noi_tuan_2" README.md .gitignore
git commit -m "Them bai Thap Ha Noi tuan 2: de quy va khu de quy"
git push origin master
```

- `add`: chọn thay đổi đưa vào commit.
- `commit`: lưu một mốc thay đổi trong repository trên máy, chưa tải lên GitHub.
- `push`: đưa các commit trên máy lên GitHub; cần đăng nhập tài khoản có quyền ghi.

Nếu `push` bị từ chối vì có commit mới trên GitHub, commit phần đang làm rồi
chạy `git pull --rebase origin master`, giải quyết xung đột nếu có và push lại.
Khi rebase có xung đột, sửa file, `git add <file>` rồi `git rebase --continue`;
dùng `git rebase --abort` nếu muốn hủy thao tác rebase.

## Nộp bài

Nộp [link GitHub Study](https://github.com/minion2007vu-bit/Study)
hoặc link trực tiếp đến thư mục bài theo tuần. Không nộp file nguồn riêng.
Các file thực thi và file biên dịch được bỏ qua bởi `.gitignore`.

## Bài cũ: slide 26

Nop bai tap mon CTDL&GT co Hue (slide 26)
                                                                      Giải thuật:
- Đầu vào (Input):

Dữ liệu của người dùng cần gợi ý "user_1" và một người dùng khác "user_2", bao gồm các danh sách: bài hát đã nghe, bài hát đã thích, bài hát đã tải xuống
Một giá trị ngưỡng tương đồng "thresh_hold"

- Đầu ra (Output):

Danh sách (tối đa 10) bài hát gợi ý cho "user_1", được sắp xếp theo số lượng yêu thích giảm dần

Các bước của giải thuật:

- Bước 1: Tính toán độ tương đồng "Similarity Score" giữa hai người dùng:

+) Duyệt qua danh sách bài hát của "user_1" và đối chiếu với Hash Map của "user_2" để tìm các tập hợp giao nhau:
+) Tập hợp các bài hát cả hai cùng tải "mutual_downloaded"
+) Tập hợp các bài hát cả hai cùng thích "mutual_likes"
+) Tập hợp các bài hát cả hai cùng nghe "mutual_songs"
+) Tính tổng điểm tương đồng "similarity_score" theo công thức:

  Điểm = (Số bài cùng tải * 5) + (Số bài cùng thích * 3) + (Số bài cùng nghe * 0.2)

- Bước 2: Kiểm tra điều kiện ngưỡng:

+) So sánh "similarity_score" với "thresh_hold"
+) Nếu "similarity_score < thresh_hold": Hai người dùng không đủ độ tương đồng, thuật toán kết thúc và không đưa ra gợi ý
+) Nếu "similarity_score >= thresh_hold": Tiếp tục Bước 3

- Bước 3: Trích xuất danh sách bài hát tiềm năng (Lọc bài hát gợi ý):

+) Tạo một danh sách rỗng để chứa bài hát gợi ý
+) Duyệt qua toàn bộ danh sách các bài hát mà "user_2" đã nghe (lịch sử nghe):
  Điều kiện 1: Kiểm tra xem bài hát này đã tồn tại trong lịch sử nghe của "user_1" hay chưa. Nếu "user_1" chưa từng nghe, đưa bài hát vào danh sách trung gian "unmutual_songs"

+) Duyệt qua danh sách trung gian vừa tạo:
  Điều kiện 2: Kiểm tra xem "user_2" có "Thích" bài hát này không (nằm trong "liked_map" của "user_2")
+) Nếu thỏa mãn cả 2 điều kiện (User 1 chưa nghe VÀ User 2 đã thích), thêm bài hát vào danh sách gợi ý chính thức

- Bước 4: Xếp hạng và xuất kết quả:

+) Sắp xếp danh sách bài hát gợi ý chính thức theo thứ tự giảm dần dựa trên thuộc tính "likes_count" (tổng lượt thích của bài hát)
+) Cắt lấy tối đa 10 bài hát đứng đầu danh sách
+) Trích xuất và in tên (song_name) của các bài hát này ra màn hình. Kết thúc thuật toán
