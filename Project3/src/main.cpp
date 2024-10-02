#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

<<<<<<< HEAD

LED led1(LED1_PIN, HIGH); 
LED led2(LED2_PIN, HIGH);  

OneButton buttonBuiltIn(BTN_PIN_BUILTIN, LOW);   
OneButton buttonSecond(BTN_PIN_SECOND, LOW); // 

bool ActiveControlLED1 = true; // Biến để theo dõi LED nào đang được điều khiển

// single click 
void btnSecondClick() {
    if (ActiveControlLED1) {
        led1.flip(); 
=======
#define LED1_PIN 2 
#define LED2_PIN 4 
#define BTN_PIN_BUILTIN 0 
#define BTN_PIN_SECOND 5   

LED led1(LED1_PIN, HIGH);  
LED led2(LED2_PIN, HIGH);  

OneButton buttonBuiltIn(BTN_PIN_BUILTIN, LOW);  
OneButton buttonSecond(BTN_PIN_SECOND, LOW);

bool ActiveControlLED1 = true; // Biến để theo dõi LED nào đang được điều khiển

// single click
void btnSecondClick() {
    if (ActiveControlLED1) {
        led1.flip(); 
    } else {
>>>>>>> 6d002fbabe133c7d751c80d64275946f7f7afa72
        led2.flip(); 
    }
}

<<<<<<< HEAD
//  double click 
=======
// double click 
>>>>>>> 6d002fbabe133c7d751c80d64275946f7f7afa72
void btnSecondDoubleClick() {
    ActiveControlLED1 = !ActiveControlLED1; 
}

<<<<<<< HEAD
// long press 
=======
// long press
>>>>>>> 6d002fbabe133c7d751c80d64275946f7f7afa72
void btnSecondHold() {
    if (ActiveControlLED1) {
        led1.blink(200); 
    } else {
<<<<<<< HEAD
        led2.blink(200); 
=======
        led2.blink(200);
>>>>>>> 6d002fbabe133c7d751c80d64275946f7f7afa72
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
<<<<<<< HEAD
    led2.loop(); 
    buttonSecond.tick(); 
    buttonBuiltIn.tick(); 
=======
    led2.loop();
    buttonSecond.tick(); 
    buttonBuiltIn.tick();
>>>>>>> 6d002fbabe133c7d751c80d64275946f7f7afa72
}
