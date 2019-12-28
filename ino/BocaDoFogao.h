#ifndef BOCADOFOGAO_H
#define BOCADOFOGAO_H

#include <math.h>
#include <Arduino.h>
#include <Servo.h>

class BocaDoFogao : public Servo {
    public:
        void iniciarBocaDoFogao(uint8_t, uint8_t, uint8_t, uint8_t);
        void prepareSensors();
        void keepEverythingTogether();
        void lightUp();
        void switchToManualMode();
        void switchToAutoMode();
        void increasePassedTime(uint32_t);
        void increaseTemp();
        void decreaseTemp();
       
        void setPower(uint8_t);
        void setExpectedTemp(uint8_t);
        void setNewTime(uint32_t);
        bool getManualModeOn();
        bool getFireIsUp();
        uint8_t getTemp();
        uint8_t getPower();
        uint8_t getPortFaisca();
        uint8_t getPortSensorDeFogo();
        uint8_t getPortControleTemperatura();
        uint8_t getPortSensorDeTemperatura();
        uint8_t getPortSensorDeGas();
        uint8_t getExpectedTemp();
        uint32_t getKeepFireOnFor();
        uint32_t getTimePassed();
        uint32_t getTimeRemaining();
        Servo* myServo;

    private:
        bool manualMode;
        uint8_t power;
        uint8_t expectedTemp;
        uint8_t portFaisca;
        uint8_t portSensorDeFogo;
        uint8_t portControleTemperatura;
        uint8_t portSensorDeTemperatura;
        uint8_t portSensorDeGas;
        uint32_t timePassed;
        uint32_t keepFireOnFor;
};


#endif // BOCA_DO_FOGAO_H
