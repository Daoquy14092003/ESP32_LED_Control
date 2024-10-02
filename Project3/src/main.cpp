#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

#define LED1_PIN 2  // LED 1 (built-in)
#define LED2_PIN 4  // LED 2
#define BTN_PIN_BUILTIN 0 // Nút bấm built-in
#define BTN_PIN_SECOND 5   // Nút bấm thứ hai

LED led1(LED1_PIN, HIGH);  // Khởi tạo LED1
LED led2(LED2_PIN, HIGH);  // Khởi tạo LED2

OneButton buttonBuiltIn(BTN_PIN_BUILTIN, LOW);   // Nút bấm built-in
OneButton buttonSecond(BTN_PIN_SECOND, LOW); // Nút bấm thứ hai

bool controllingLED1 = true; // Biến để theo dõi LED nào đang được điều khiển

// Hàm xử lý single click cho nút bấm thứ hai
void btnSecondClick() {
    if (controllingLED1) {
        led1.flip(); // Bật/tắt LED1
    } else {
        led2.flip(); // Bật/tắt LED2
    }
}

// Hàm xử lý double click cho nút bấm thứ hai
void btnSecondDoubleClick() {
    controllingLED1 = !controllingLED1; // Chuyển đổi giữa LED1 và LED2
}

// Hàm xử lý long press cho nút bấm thứ hai
void btnSecondHold() {
    if (controllingLED1) {
        led1.blink(200); // Nháy LED1
    } else {
        led2.blink(200); // Nháy LED2
    }
}

void setup() {
    led1.off(); // Tắt LED1
    led2.off(); // Tắt LED2
    buttonSecond.attachClick(btnSecondClick); // Gán hàm xử lý click cho nút bấm thứ hai
    buttonSecond.attachDoubleClick(btnSecondDoubleClick); // Gán hàm xử lý double click cho nút bấm thứ hai
    buttonSecond.attachLongPressStart(btnSecondHold); // Gán hàm xử lý long press cho nút bấm thứ hai
}

void loop() {
    led1.loop(); // Cập nhật trạng thái LED1
    led2.loop(); // Cập nhật trạng thái LED2
    buttonSecond.tick(); // Cập nhật trạng thái nút bấm thứ hai
    buttonBuiltIn.tick(); // Cập nhật trạng thái nút bấm built-in (nếu cần)
}
