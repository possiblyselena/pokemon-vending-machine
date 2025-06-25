// WIP I wrote some logic, but I will finish it off once I get my parts so I can test things better than doing it in TinkerCAD
//#include <HCSR04.h>
#include <LiquidCrystal_I2C.h>

int machineState = 3;

const int leftButton = 1;
const int rightButton = 2;

int leftState = 0;
int rightState = 0;

LiquidCrystal_I2C lcd_1(32, 16, 2);

void setup() {
  lcd_1.init();

  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
   
}

void loop() {
  if (digitalRead(leftState) == HIGH || digitalRead(rightState) == HIGH) {
    switch (machineState) {
    case 0:
  		lcd_1.clear();
  		lcd_1.setCursor(0,0);
  		lcd_1.print("insert coin");
  		delay(1000);
  		lcd_1.setCursor(0,1);
        lcd_1.print("to start!");
      	// Wait until motion sensor detects coin
    	machineState = 1;
    	break;
    case 1: 
    	lcd_1.clear();
  		lcd_1.setCursor(2,0);
  		lcd_1.print("select row:");
  		delay(1000);
  		lcd_1.setCursor(5,1);
        lcd_1.print("A or B");
      	// wait until selections and store it in a variable
    	machineState = 2;
    	break;
    case 2:
    	lcd_1.clear();
  		lcd_1.setCursor(0,0);
  		lcd_1.print("select column:");
  		delay(1000);
  		lcd_1.setCursor(5,1);
        lcd_1.print("1 or 2");
      	// wait until selections and store it in a variable
    	machineState = 3;
    	break;
    case 3:
    	lcd_1.clear();
  		lcd_1.setCursor(0,0);
  		lcd_1.print("cards await");
  		delay(1000);
  		lcd_1.setCursor(7,1);
        lcd_1.print("...");
      	// Look at what variable to know which servo to let off
    	machineState = 0;
    } 
    
  }
}
