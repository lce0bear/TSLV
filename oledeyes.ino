#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void draw_eyes();
void blink(int speed = 12);
void happy();


int touch1=2;
int timeD = 1000;
int ht=42;

void draw_eyes() {
  display.clearDisplay();
  //draw from center
 display.clearDisplay();

display.fillRoundRect(12, 9, 46, ht, 5, 1);

display.fillRoundRect(64, 9, 45, ht, 5, 1);

display.display();
  
}



void blink(int speed) {
  draw_eyes();

  for (int i = 0; i < 3; i++) {
    ht= ht - speed;
    
    draw_eyes();
    delay(1);
  }
  for (int i = 0; i < 3; i++) {
    ht = ht + speed;
    

    draw_eyes();
    delay(1);
  }
delay(1500);
}

void happy(){
  display.clearDisplay();

display.fillRoundRect(12, 9, 46, 42, 5, 1);

display.fillRoundRect(66, 9, 46, 42, 5, 1);

display.fillCircle(88, 44, 24, 0);

display.fillCircle(34, 44, 24, 0);

display.display();
delay(2000);
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  
  // Clear the buffer
  display.clearDisplay();


  display.display();
  delay(timeD);
 
}



void loop() {
  int touch=digitalRead(touch1);
 draw_eyes();
 blink();
if (touch==HIGH)
 happy();
else
 blink();



  

}
