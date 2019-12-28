#include "LcdFogao.h"

LcdFogao::LcdFogao() {
  lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  lcd->begin(16, 2);
}

void LcdFogao::displayStatusScreen(uint8_t currentMode, uint8_t power, uint8_t temp) {
  // Line 1
  this->displayTitle(currentMode);

  // Line 2
  this->displayCurrentStatus(power, temp);
}

uint8_t LcdFogao::getPressedButton() {
  // Possible returns:
  // 0 -> [NO BUTTON]
  // 1 -> BUTTON SELECT
  // 2 -> BUTTON LEFT
  // 3 -> BUTTON DOWN
  // 4 -> BUTTON UP
  // 5 -> BUTTON RIGHT
  uint32_t inputFromLcdShield = analogRead(A0);

  if (inputFromLcdShield > 800)
    return 0;

  else if (inputFromLcdShield > 600)
    return 1;

  else if (inputFromLcdShield > 400)
    return 2;

  else if (inputFromLcdShield > 200)
    return 3;

  else if (inputFromLcdShield > 80)
    return 4;

  else
    return 5;
}


// Private Methods
void LcdFogao::displayTitle(uint8_t currentMode) {
  switch (currentMode) {
    case 1:
      displayManualModeTitle();
      break;
    case 2:
      displayMobileModeTitle();
      break;
  }
}

void LcdFogao::displayCurrentStatus(uint8_t power, uint8_t temp) {
  this->displayStatusCase();
  this->displayPower(power);
  this->displayTemp(temp);
}

void LcdFogao::displayStatusCase() {
  // Display the second line without the Temperature and Power
  lcd->setCursor(0, 1);
  lcd->print("Pow:    Temp:   ");
}

void LcdFogao::displayPower(uint8_t power) {
  lcd->setCursor(4, 1);
  lcd->print(power);
}

void LcdFogao::displayTemp(uint8_t temp) {
  lcd->setCursor( (temp < 100) ? (14) : (13), 1);
  lcd->print(temp);
}

void LcdFogao::displayManualModeTitle() {
  lcd->setCursor(0, 0);
  lcd->print("Manual Mode  ***");
}

void LcdFogao::displayMobileModeTitle() {
  lcd->setCursor(0, 0);
  lcd->print("Mobile Mode  ***");
}
