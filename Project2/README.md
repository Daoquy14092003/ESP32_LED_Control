# Platform IO: ESP32 LED Control with Button and Double Click Feature (Project2)
By Đào Ngọc Quý

# Mục đích : 
- Làm quen với PlatformIO
- Làm quen với Git, Github
  
## Phần cứng 
Trong dự án này, tôi sử dụng board phát triển ESP32 Devkit v1:
    - Con chip ESP32 kiến trúc xtensa, lõi kép
    - Tích hợp Blue LED vào chân GPIO02, active level = HIGH 
    - Tích hợp nút bấm (BOOT) vào chân GPIO00, active level = LOW

## Yêu cầu chức năng 
Chương trình có chức năng sau:
  - bấm nút một lần (single click) để bật/tắt LED (đảo trạng thái).
  - sử dụng double click để chuyển sang trạng thái nhấp nháy liên tục (blink 200ms một lần)
  - nếu tiếp tục nhấn single click thì LED lại chuyển trạng thái bật/tắt 

## Các công cụ trong `workspace` này
- Sử dụng thư viện OneButton (open source lib) để đạt chức năng tương tự. Xem chi tiết hướng dẫn trong `OneButton_Lib_Demo/README.md`
- Sử dụng các thư viện tự phát triển 
