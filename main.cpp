#include <Arduino.h>
#include <LiquidCrystal.h> 

// select the pins used on the LCD panel 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

extern HardwareSerial Serial;
unsigned int time;
void(* resetFunc) (void) = 0;

void setup() {
   // initialize digital pin LED_BUILTIN as an output.
//    pinMode(LED_BUILTIN, OUTPUT);
//    Serial.begin(115200);
//    while (!Serial) {
//      ; // wait for serial port to connect. Needed for native USB port only
//    }
    lcd.begin(16, 2);              // start the library 
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Booting up...."); // print a simple message 
    delay(1000);
    lcd.clear();
}

void loop() {
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);  
//  Serial.println("Out");
    time = millis()/1000;
    lcd.setCursor(9,1);  // move cursor to second line "1" and 9 spaces over 
    lcd.print(time);      // display seconds elapsed since power-up 
    delay(1000);
    if (time > 9)
    {
        lcd.setCursor(0,0);
        lcd.print("Reseting now...");
        delay(2000);
        resetFunc();
    }
}