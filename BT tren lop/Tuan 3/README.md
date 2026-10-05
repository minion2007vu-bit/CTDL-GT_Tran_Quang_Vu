Bài toán Đệ quy Tháp Hà Nội:

Khởi tạo số đĩa n, cột gốc A, cột đích B, cột trung gian C
Gọi hàm thapHaNoi(n, goc, dich, trung_gian):- Nếu n = 1, kết thúc lời gọi hàm
Gọi đệ quy với n − 1 đĩa từ cột gốc sang cột trung gian, dùng cột đích làm phụ
Gọi đệ quy với n − 1 đĩa từ cột trung gian sang cột đích, dùng cột gốc làm phụ
Khi các lời gọi kết thúc, in thông báo hoàn thành
Kết thúc chương trình

Bài toán khử đệ quy:

Chương trình dùng vòng lặp và vector để chuyển n đĩa từ cột A sang cột B, dùng cột C làm trung gian
Mỗi công việc lưu số đĩa, các cột và trạng thái xử lý
Chương trình lấy công việc ở đầu vector
Nếu chỉ cần chuyển một đĩa thì in bước chuyển
Nếu không, chia thành ba công việc và chèn theo thứ tự ngược để xử lý đúng thứ tự
