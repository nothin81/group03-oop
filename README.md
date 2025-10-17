## Gioi thieu

* Day la git repo cua nhom 3!
* 10/17/2025

# Đề tài: ỨNG DỤNG ĐẶT VÉ PHIM ONLINE 

## Mục tiêu và mô tả ngắn gọn
Xây dựng chương trình đặt vé xem phim online cho phép người dùng:
* Đăng ký, đăng nhập
* Chọn rạp, phim, suất chiếu, ghế
* Thanh toán và nhận vé
* Quản lý phim, rạp, nhân viên, thống kê doanh thu
Chạy trên môi trường console ( Lựa chọn giao diện: dòng lệnh hoặc qua website) 

## Cơ sở dữ liệu (lưu trữ & trích xuất)
Cơ sở dữ liệu lựa chọn: (Mức dễ) Lưu trữ file .txt hoặc .csv ; (TB) SQLite ; (Khó) SQL sv management 

## Thiết kế chương trình (tóm tắt lớp)
| Lớp | Mô tả | Vai trò |
|-------|-------|-------|
| `User` | Lớp cha (id, name, role, password) | Kế thừa bởi Customer, Staff, Admin |
| `Customer`, `Staff`, `Admin` | Người dùng cụ thể | Thao tác riêng cho từng loại người dùng |
| `Movie` | Thông tin phim | Quản lý danh sách phim |
| `Showtime` | Suất chiếu | Liên kết Movie và Room |
| `Room` | Phòng chiếu (có danh sách ghế) | Hiển thị và chọn ghế |
| `Booking` | Đặt vé | Liên kết Customer, Showtime, Seat |
| `FileManager` | Lớp chuyên đọc/ghi dữ liệu | Trích xuất từ file text |
| `Payment` | Thanh toán giả lập | Xác nhận vé và in ra hóa đơn |

## Thành viên & phân công
| Thành viên | Vai trò | Nhiệm vụ |
|-------------|----------|-----------|
| S1 | Kiến trúc hệ thống, lớp usr | `User`, `Auth` |
| S2 | Quản lý phim, suất chiếu | `Movie`, `Showtime` ,`movies.txt`, `showtimes.txt`|
| S3 | Phòng chiếu | `Room`, `Seat` |
| S4 | Đặt vé | `Booking`, `Payment`, `data/booking.txt` |
| S5 | Giao diện | `main.cpp` |

## Thuyết trình nhóm (5 người)

