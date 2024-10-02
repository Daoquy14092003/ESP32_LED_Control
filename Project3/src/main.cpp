#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>


LED led1(LED1_PIN, HIGH); 
LED led2(LED2_PIN, HIGH);  

OneButton buttonBuiltIn(BTN_PIN_BUILTIN, LOW);   
OneButton buttonSecond(BTN_PIN_SECOND, LOW); // 

bool ActiveControlLED1 = true; // Biến để theo dõi LED nào đang được điều khiển

// single click 
void btnSecondClick() {
    if (ActiveControlLED1) {
        led1.flip(); 
        led2.flip(); 
    }
}

//  double click 
void btnSecondDoubleClick() {
    ActiveControlLED1 = !ActiveControlLED1; 
}

// long press 
void btnSecondHold() {
    if (ActiveControlLED1) {
        led1.blink(200); 
    } else {
        led2.blink(200); 
    }
}

void setup() {
    led1.off(); 
    led2.off(); 
    buttonSecond.attachClick(btnSecondClick); 
    buttonSecond.attachDoubleClick(btnSecondDoubleClick); 
    buttonSecond.attachLongPressStart(btnSecondHold); 
}

void loop() {
    led1.loop(); 
    led2.loop(); 
    buttonSecond.tick(); 
    buttonBuiltIn.tick(); 
}
