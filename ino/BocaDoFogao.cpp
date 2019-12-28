#include "BocaDoFogao.h"


void BocaDoFogao::iniciarBocaDoFogao(
    uint8_t portFaisca,
    uint8_t portSensorDeFogo,
    uint8_t portControleTemperatura,
    uint8_t portSensorDeTemperatura)
{
    this->portFaisca = portFaisca;
    this->portSensorDeFogo = portSensorDeFogo;
    this->portControleTemperatura = portControleTemperatura;
    this->portSensorDeTemperatura = portSensorDeTemperatura;

    pinMode(this->portFaisca, OUTPUT);
    pinMode(this->portSensorDeFogo, INPUT);
    pinMode(this->portControleTemperatura, OUTPUT);
    pinMode(this->portSensorDeTemperatura, INPUT);

    // Iniciando Servo
    this->myServo = new Servo();
    this->myServo->attach(this->portControleTemperatura);

    // Estado inicial do fogão ao ligar
    this->manualMode = true;
    this->power = 2;
    this->expectedTemp = 60;
}

void BocaDoFogao::keepEverythingTogether() {       
    uint8_t currentTemp = this->getTemp() / this->getExpectedTemp();
    uint8_t newPower = 3;
    if (currentTemp > 0.5)
        newPower = 2;

    else if (currentTemp > 0.75)
        newPower = 1;

    else if (currentTemp > 1.05 || (!this->manualMode && ( (this->getTimePassed() > this->keepFireOnFor) )))
        newPower = 0;
    
    this->setPower(newPower);
    if (this->getPower() != 0)
        this->lightUp();
}

void BocaDoFogao::lightUp() {
    while (!this->getFireIsUp()) {
        digitalWrite(this->portFaisca, HIGH);
    }
    digitalWrite(this->portFaisca, LOW);
}

void BocaDoFogao::switchToManualMode() {
    this->manualMode = true;
}

void BocaDoFogao::switchToAutoMode() {
    this->manualMode = false;
}

void BocaDoFogao::increasePassedTime(uint32_t timePassed) {
    this->timePassed += timePassed;
}

void BocaDoFogao::increaseTemp() {
    if (this->getExpectedTemp() < 110) {
        this->expectedTemp += 5;
    }
}

void BocaDoFogao::decreaseTemp() {
    if (this->getExpectedTemp() > 50) {
        this->expectedTemp -= 5;
    }
}


void BocaDoFogao::setPower(uint8_t power) {
    this->power = power;

    switch (power) {
        case 0:
            this->myServo->write(0);
            break;
        case 1:
            this->myServo->write(180);
            break;
        case 2:
            this->myServo->write(90);
            break;
        case 3:
            this->myServo->write(20);
            break;
    }
}

void BocaDoFogao::setExpectedTemp(uint8_t newTemp) {
    this->expectedTemp = newTemp;
}

void BocaDoFogao::setNewTime(uint32_t time) {
    this->keepFireOnFor = time;
    this->timePassed = millis();
}

bool BocaDoFogao::getManualModeOn() {
    return this->manualMode;
}

bool BocaDoFogao::getFireIsUp() {
    return digitalRead(this->portSensorDeFogo);
}

uint8_t BocaDoFogao::getTemp() {
    double Temp;
    Temp = log(10000.0 / (1024.0 / analogRead(this->portSensorDeTemperatura) - 1));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
    Temp = Temp - 273.15;
    return (uint8_t) Temp;
}

uint8_t BocaDoFogao::getPower() {
    return power;
}

uint8_t BocaDoFogao::getPortFaisca() {
    return portFaisca;
}

uint8_t BocaDoFogao::getPortSensorDeFogo() {
    return portSensorDeFogo;
}

uint8_t BocaDoFogao::getPortControleTemperatura() {
    return portControleTemperatura;
}

uint8_t BocaDoFogao::getPortSensorDeTemperatura() {
    return portSensorDeTemperatura;
}

uint8_t BocaDoFogao::getPortSensorDeGas() {
    return portSensorDeGas;
}

uint8_t BocaDoFogao::getExpectedTemp() {
    return expectedTemp;
}

uint32_t BocaDoFogao::getKeepFireOnFor() {
    return this->keepFireOnFor;
}

uint32_t BocaDoFogao::getTimePassed() {
    return millis() - this->timePassed;
}

uint32_t BocaDoFogao::getTimeRemaining() {
    return this->getKeepFireOnFor() - this->getTimePassed();
}
