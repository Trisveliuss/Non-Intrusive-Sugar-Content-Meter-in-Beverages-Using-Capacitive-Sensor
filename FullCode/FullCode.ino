//----- OLED -----//
#include "OLED.h"

//----- Encoder ------//
#include <SimpleRotary.h>
SimpleRotary rotary(1, 0, 2);
int mode = 0;

void setup() {
  Serial.begin(115200);
  OLED::setup();
  rotary.setDebounceDelay(5);
}

void loop() {
  int dir = rotary.rotate();
  int butt = rotary.pushType(1000);

  if (mode == 0) {
    if (butt == 1) {
      Serial.println("Short");
      Serial.println("Mode 1");
      mode = 1;
    }
    if (dir == 1) {
      OLED::next();
    }
    if (dir == 2) {
      OLED::previous();
    }
    OLED::menu();

  } else if (mode == 1) {
    if (butt == 2) {
      Serial.println("Long");
      Serial.println("Mode 0");
      mode = 0;
    }
    switch (OLED::item_selected) {
      case 0:
        OLED::brix();
        break;
      case 1:
        OLED::gram();
        break;
      case 2:
        OLED::adc();
        break;
      case 3:
        OLED::volt();
        break;
      case 4:
        OLED::info();
        break;
      default:
        break;
    }
  }
}
