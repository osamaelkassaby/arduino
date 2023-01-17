#include <LiquidCrystal.h>
#include "WiFi.h"
LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
const char *message = "OSAMAELKASSBAY";


void setup() {
  // put your setup code here, to run once:

lcd.begin(16,2);
lcd.setCursor(0,0);

    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.home();
  lcd.setCursor(1,0);


   Serial.println("scan start");
   //lcd.print("scan start");
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    lcd.clear();
    lcd.print("scan done");
    delay(1500);
    lcd.clear();
    if (n == 0) {
        Serial.println("no networks found");
        lcd.clear();
        lcd.print("no network found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
//            lcd.clear();
            for(int d =0; d <i; ++d){
               lcd.setCursor(1,0);
            lcd.clear();
            delay(100);
            lcd.print(WiFi.SSID(i));
             delay(1000);
         //   lcd.clear();
            lcd.setCursor(0,1);
            delay(100);
            lcd.print(WiFi.RSSI(i));
             delay(1000);
              }
           
            delay(100);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}

//#define CLOCK 32 //D-
//#define DATA 33 //D+
//
//#include <LiquidCrystal.h>  //Best imported by library manager
//
//const char keymap[] = {
//  0, 0,  0,  0,  0,  0,  0,  0,
//  0, 0,  0,  0,  0,  0, '`', 0,
//  0, 0 , 0 , 0,  0, 'q','1', 0,
//  0, 0, 'z','s','a','w','2', 0,
//  0,'c','x','d','e','4','3', 0,
//  0,' ','v','f','t','r','5', 0,
//  0,'n','b','h','g','y','6', 0,
//  0, 0, 'm','j','u','7','8', 0,
//  0,',','k','i','o','0','9', 0,
//  0,'.','/','l',';','p','-', 0,
//  0, 0,'\'', 0,'[', '=', 0, 0,
//  0, 0,13, ']', 0, '\\', 0, 0,
//  0, 0, 0, 0, 0, 0, 127, 0,
//  0,'1', 0,'4','7', 0, 0, 0,
//  '0','.','2','5','6','8', 0, 0,
//  0,'+','3','-','*','9', 0, 0,
//  0, 0, 0, 0 };
//
//LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
//
//void setup()
//{
//  Serial.begin(115200);
//  pinMode(CLOCK, INPUT_PULLUP); //For most keyboards the builtin pullups are sufficient, so the 10k pullups can be omitted
//  pinMode(DATA, INPUT_PULLUP);
//  lcd.begin(20, 4);
//  lcd.cursor();
//  lcd.blink();
// 
// }
//
//void loop()
//{
//  uint16_t scanval = 0;
//  for(int i = 0; i<11; i++)
//  {
//    while(digitalRead(CLOCK));
//    scanval |= digitalRead(DATA) << i;
//    while(!digitalRead(CLOCK));
//  }
//  scanval >>= 1;
//  scanval &= 0xFF;
//  Serial.println(scanval, HEX);
//}
