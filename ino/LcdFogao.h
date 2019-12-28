#ifndef LCDFOGAO_H
#define LCDFOGAO_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class LcdFogao {
  public:
    LcdFogao();
    void displayHomeScreen();
    void displayStatusScreen(uint8_t, uint8_t, uint8_t);
    uint8_t getPressedButton();

  private:
    void displayTitle(uint8_t);
    void displayCurrentStatus(uint8_t, uint8_t);
    void displayMobileModeTitle();
    void displayManualModeTitle();
    void displayStatusCase();
    void displayPower(uint8_t);
    void displayTemp(uint8_t);
    LiquidCrystal* lcd;
};

#endif // LCDFOGAO_H
